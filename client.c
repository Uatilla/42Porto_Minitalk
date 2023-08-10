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

#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*--------------------------------------------------------------*/
int	ft_atoi(const char *nptr)
{
	int	signal;
	int	number;

	signal = 1;
	number = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
	{
		nptr++;
	}
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
		{
			signal = signal * (-1);
		}
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		number *= 10;
		number += *nptr - 48;
		nptr++;
	}
	return (signal * number);
}
/*--------------------------------------------------------------*/
/*void    convert_binary(int pid, unsigned char character)
{
    unsigned char binary_pos;
    //DONE! 4) Convert my message into binary and the signal (SIGUSR1 = 1, SIGUSR2 = 0)
    binary_pos = 128;
    while(binary_pos)
    {
        if (binary_pos & character)
        {
            kill(pid, SIGUSR1);
            printf("1");
        }
        else
        {
            kill(pid, SIGUSR2);
            printf("0");
        }
        binary_pos >>= 1;
        usleep(200);
    }
}*/

void	convert_binary(int pid, char i)
{
	int	bit;
    //DONE! 4) Convert my message into binary and the signal (SIGUSR1 = 1, SIGUSR2 = 0)
	bit = 0;
	while (bit < 8)
	{
		if ((i & (0x01 << bit)) != 0) //set the value of bit (1) in the position of the bit variable (first iteration will be: 00000001, second iteration 00000010...)
		{
            kill(pid, SIGUSR1);
            //printf("1");
        }
		else
        {
			kill(pid, SIGUSR2);
            //printf("0");
        }
		usleep(500);
		bit++;
	}
}

void    send_msg(int pid, char *msg)
{    
    //printf("PID: %d\n", pid);
    while(*msg)
    {
        printf("%c",*msg);
        convert_binary(pid, *msg);
        msg++;
    }
}
int main(int argc, char **argv)
{
    int i;

    i = 0;
    //DONE! 1) Verify if is there only two arguments (PID and message).
    if (argc != 3)
        exit(write(1, "Error: Wrong format!", 20)); 
    //DONE! 2) Verify if the PID informed is a valid numeric value, before modifying it to int.
    while (argv[1][i]!= '\0')
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
            exit(write(1, "ERROR: PID invalid!\n", 20));
        i++;
    }
    //DONE! 3) Convert the PID from char * to int, then convert the message into binary.
    send_msg(ft_atoi(argv[1]), argv[2]);
    printf("|");
    send_msg(ft_atoi(argv[1]), "\n");
    
    if (argv[1][i] == '\0')
        write(1, "Message sent!\n", 14);
    return (0);
}
