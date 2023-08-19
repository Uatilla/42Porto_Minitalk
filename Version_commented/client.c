/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:52:45 by uviana-a          #+#    #+#             */
/*   Updated: 2023/08/01 17:52:55 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_binary(int pid, char i)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		//5) Send the signal as the bit value (SIGUSR1 = 1, SIGUSR2 = 0).
		if ((i & (0x01 << bit)) != 0)
		{
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

void	send_msg(int pid, char *msg)
{
	//4) Convert the message into binary.
	while (*msg)
	{
		convert_binary(pid, *msg);
		msg++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	//1) Check if is there only two arguments (PID and message).
	if (argc != 3)
		exit(write(1, "Error: Wrong format!", 20));
	//2) Check if the PID is valid (only numbers).
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] < '0' || argv[1][i] > '9')
			exit(write(1, "ERROR: PID invalid!\n", 20));
		i++;
	}
	//3) Send the message.
	send_msg(ft_atoi(argv[1]), argv[2]);
	send_msg(ft_atoi(argv[1]), "\n");
	if (argv[1][i] == '\0')
		write(1, "Message sent!\n", 14);
	return (0);
}
