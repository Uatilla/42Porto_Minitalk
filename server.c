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

/*static void ft_listening_data(int signal)
{
    //DONE! 4) The signal is correctly receipt.
    //5) Now I need to convert the binary into char
    //6) Put this char into a const char* variable
    //7) When there is no more signals, add a '\0' at the end of the const variable and print it.
    if (signal == SIGUSR1)
    {
        write(1, "1", 1);
        //printf("%d\n", SIGUSR1);
    }
    else if (signal == SIGUSR2)
    {
        write(1, "0", 1);
        //printf("%d\n", SIGUSR2);
    }
    else
        write(1, "-", 1);
}*/

void	ft_listening_data(int sig)
{
    //DONE! 4) The signal is correctly receipt.
    //5) Now I need to convert the binary into char
    //6) Put this char into a const char* variable
    //7) When there is no more signals, add a '\0' at the end of the const variable and print it.
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		printf("%c", i);
		bit = 0;
		i = 0;
	}
}


int main(void)
{
    //DONE! 1) Print the server PID. (CHANGE THE PRINTF BY PUTNBR AND PUTSTR);
    printf("PID: %d\n", getpid());
    //DONE! 3)Define what the each signal (SIGUSR1 = 1 and SIGUSR2 = 0) should do when received by the server.
    signal(SIGUSR1, ft_listening_data);
    signal(SIGUSR2, ft_listening_data);
    //DONE! 2) Keep the program running "listening" for signals.
    while (1)
    {     
        pause();
    }
}

