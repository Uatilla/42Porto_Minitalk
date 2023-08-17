/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:52:45 by uviana-a          #+#    #+#             */
/*   Updated: 2023/08/17 21:17:13 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int		ft_atoi(const char *nptr);

void	ft_putstr_fd(char *s, int fd);

void	ft_putnbr(unsigned int pid);

void	convert_binary(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

void	send_msg(int pid, char *msg)
{
	while (*msg)
	{
		convert_binary(pid, *msg);
		msg++;
	}
}

static	void	msg_done_signal(int signum)
{
	if (signum == SIGUSR2)
		ft_putstr_fd("Message received by the server succesfully!\n", 1);
}

int	main(int argc, char **argv)
{
	struct sigaction	clt_signal;
	int					i;

	i = 0;
	if (argc != 3)
		exit(write(1, "Error: Wrong format!", 20)); 
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
			exit(write(1, "ERROR: PID invalid!\n", 20));
		i++;
	}
	clt_signal.sa_handler = &msg_done_signal;
	clt_signal.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &clt_signal, NULL) == -1)
		ft_putstr_fd("Failed to set SIGUSR1 behavior\n", 1);
	if (sigaction(SIGUSR2, &clt_signal, NULL) == -1)
		ft_putstr_fd("Failed to set SIGUSR2 behavior\n", 1);
	send_msg(ft_atoi(argv[1]), argv[2]);
	send_msg(ft_atoi(argv[1]), "\n");
	return (0);
}
