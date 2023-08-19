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

#include "minitalk.h"

char	*g_str;

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
		//6) Return SIGUSR2 to the sender.
		if (kill(info->si_pid, SIGUSR2) == -1)
			ft_putstr_fd("Fail to return the receipt", 1);
	}
	free(c1);
}

void	ft_listening_data(int signum, siginfo_t *info, void *ucontext)
{
	static int	bit;
	static int	i;

	//4) Convert the SIGUSR1 and SIGUSR2 into binary.
	(void)ucontext;
	if (signum == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		//5) Send a byte to the global variable.
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
	//1) Print the Server PID.
	ft_putstr_fd("Server PID: [", 1);
	ft_putnbr(getpid());
	ft_putstr_fd("]\n", 1);
	//2) Define how the struct sigaction should behave.
	config_signals();
	//3) Keep the program running waiting for signals to listen.
	while (1)
		pause();
}
