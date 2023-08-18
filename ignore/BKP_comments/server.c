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

char *str;

char	*ft_strjoin_mod(char *s1, char *s2);

void	ft_listening_data(int sig)
{
    //DONE! 4) The signal is correctly receipt.
    //DONE! 5) convert the i variable (int) to a char variable
    //DONE! 6) Put this char into a const char* variable
    //DONE! 7) When there is no more signals, add a '\0' at the end of the const variable and print it.
	static int	bit;
	static int	i;
    char *c1;

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
        str = ft_strjoin_mod(str, c1);
        if (c1[0] == '\n')
        {
            printf("%s", str);
            free(str);
            str = NULL;
        }
        bit = 0;
		i = 0;
        free(c1);
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