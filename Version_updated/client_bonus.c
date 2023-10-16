/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uatilla <uatilla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:52:45 by uviana-a          #+#    #+#             */
/*   Updated: 2023/10/15 19:54:42 by uatilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		ft_putstr_fd("\nMessage received by the server succesfully!\n\n", 1);
}

int	main(int argc, char **argv)
{
	struct sigaction	clt_signal;
	int					i;
	const	char *msg;

	i = 0;
	msg = "\n\nError: Wrong format! The structure was not followed, please insert in this way:\n\n\t\t\t./client_bonus <PID> (1) message\n\n\nExample: ./client_bonus 1234 42Porto\n\n(1) The message can contain any number of elements.\nYou just need to add double quotes when sending more than one word, like this: \"42 Porto :)\"\n\nExample: ./client_bonus 1234 \"42 Porto :)\"\n\n";
	if (argc != 3)
		exit(write(1, msg, ft_strlen(msg)));
	msg = "\n\nError: PID invalid!\n\nThe server PID has only numbers.\n\n";
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
			exit(write(1, msg, ft_strlen(msg)));
		i++;
	}
	clt_signal.sa_handler = &msg_done_signal;
	clt_signal.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &clt_signal, NULL) == -1)
		ft_putstr_fd("Failed to set SIGUSR1 behavior\n", 1);
	if (sigaction(SIGUSR2, &clt_signal, NULL) == -1)
		ft_putstr_fd("Failed to set SIGUSR2 behavior\n", 1);
	i = 0;

	send_msg(ft_atoi(argv[1]), argv[2]);
	send_msg(ft_atoi(argv[1]), "\n");
	return (0);
}
