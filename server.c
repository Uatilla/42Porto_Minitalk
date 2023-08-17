/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:54:29 by uviana-a          #+#    #+#             */
/*   Updated: 2023/08/01 17:54:32 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	*g_str;

char	*ft_strjoin_mod(char *s1, char *s2);

void	ft_putstr_fd(char *s, int fd);

void	ft_putnbr(unsigned int pid);

void	ft_listening_data(int sig)
{
	static int	bit;
	static int	i;
	char		*c1;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		c1 = (char *)malloc(sizeof(char) * 2);
		if (!c1)
			return ;
		c1[0] = (char)i;
		c1[1] = '\0';
		g_str = ft_strjoin_mod(g_str, c1);
		if (c1[0] == '\n')
		{
			ft_putstr_fd(g_str, 1);
			free(g_str);
			g_str = NULL;
		}
		bit = 0;
		i = 0;
		free(c1);
	}
}

int	main(void)
{
	ft_putstr_fd("Server PID: [", 1);
	ft_putnbr(getpid());
	ft_putstr_fd("]\n", 1);
	signal(SIGUSR1, ft_listening_data);
	signal(SIGUSR2, ft_listening_data);
	while (1) 
		pause();
}
