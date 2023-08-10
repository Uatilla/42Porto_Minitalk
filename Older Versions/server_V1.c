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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_mod(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	i = -1;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	join = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!join)
		return (NULL);
	while (s1[++i] != '\0')
		join[i] = s1[i];
	j = 0;
	while (s2[j] != '\0')
		join[i++] = s2[j++];
	join[i++] = '\0';
	free(s1);
	return (join);
}

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
    //5) convert the i variable (int) to a char variable
    //6) Put this char into a const char* variable
    //7) When there is no more signals, add a '\0' at the end of the const variable and print it.
	static int	bit;
	static int	i;
    static char *str;

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		printf("%c", i);
        //str = ft_strjoin_mod(i, str);
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

