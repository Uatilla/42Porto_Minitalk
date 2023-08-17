/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:54:29 by uviana-a          #+#    #+#             */
/*   Updated: 2023/08/17 21:17:21 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

char	*g_str;

size_t	ft_strlen(const char *s);

char	*ft_strjoin_mod(char *s1, char *s2);

void	ft_putstr_fd(char *s, int fd);

void	ft_putnbr(unsigned int pid);

void	ft_process_byte(int bytevalue, siginfo_t *info)
{
	char	*c1;

	c1 = (char *)malloc(sizeof(char) * 2);
	if (!c1)
		return ;
	c1[0] = (char)bytevalue;
	c1[1] = '\0';
	g_str = ft_strjoin_mod(g_str, c1);
	if (c1[0] == '\n')
	{
		ft_putstr_fd(g_str, 1);
		free(g_str);
		g_str = NULL;
		if (kill(info->si_pid, SIGUSR2) == -1)
			ft_putstr_fd("Fail to return the receipt", 1);
	}
	free(c1);
}

void	ft_listening_data(int signum, siginfo_t *info, void *ucontext)
{
	static int	bit;
	static int	i;

	(void)ucontext;
	if (signum == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_process_byte(i, info);
		bit = 0;
		i = 0;
	}
}

static void	config_signals(void)
{
	struct sigaction	srv_signal;

	srv_signal.sa_handler = 0;
	srv_signal.sa_flags = SA_SIGINFO;
	srv_signal.sa_sigaction = &ft_listening_data;
	if (sigaction(SIGUSR1, &srv_signal, NULL) == -1)
		ft_putstr_fd("Failed to set SIGUSR1 behavior\n", 1);
	if (sigaction(SIGUSR2, &srv_signal, NULL) == -1)
		ft_putstr_fd("Failed to set the SIGUSR2 behavior\n", 1);
}

int	main(void)
{
	ft_putstr_fd("Server PID: [", 1);
	ft_putnbr(getpid());
	ft_putstr_fd("]\n", 1);
	config_signals();
	while (1)
		pause();
}
