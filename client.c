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
void    convert_binary(unsigned char character)
{
    unsigned char binary_pos;
    //DONE! 2) Convert my message into binary
    binary_pos = 128;
    while(binary_pos)
    {
        if (binary_pos & character)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        binary_pos >>= 1;
    }
    write(1, "\n", 1);
}
void    send_msg(int pid, char *msg)
{    
    printf("PID: %d", pid);
    while(*msg)
    {
        convert_binary(*msg);
        msg++;
    }
}
int main(int argc, char **argv)
{
    if (argc != 3)
        exit(write(1, "Error: Message invalid!", 23)); //DONE! 1) Before send the PID to the send_msg I need to convert it into a int.  
    send_msg(ft_atoi(argv[1]), argv[2]);
    
    //define the signal handler
    //send the right signal as the binary sent.
    return (0);
}