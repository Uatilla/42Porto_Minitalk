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
#include <stdbool.h>

char *str;

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

void	ft_listening_data(int signum, siginfo_t *info, void *ucontext)
{
    //DONE! 4) The signal is correctly receipt.
    //DONE! 5) convert the i variable (int) to a char variable
    //DONE! 6) Put this char into a const char* variable
    //DONE! 7) When there is no more signals, add a '\0' at the end of the const variable and print it.
	static int	bit;
	static int	i;
    char *c1;
    (void)ucontext;

	if (signum == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		//printf("%c", i);
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
            //DONE! 8) Send a signal to the sender that the message was already receipt.
            printf("Message received from client PID: [%d]\n", info->si_pid);
            if (kill(info->si_pid, SIGUSR2) == -1)
                printf("Server failed to send the receipt message to the client PID [%d]", info->si_pid);
        }
            
        bit = 0;
		i = 0;
        free(c1);
	}
}
static void config_signals(void)
{
    struct  sigaction   srv_signal;

    srv_signal.sa_handler = 0;
    srv_signal.sa_flags = SA_SIGINFO;
    srv_signal.sa_sigaction = &ft_listening_data;
    //If I can't set the behaviors of SIGUSR1 and SIGUSR2 then show this error.
    if (sigaction(SIGUSR1, &srv_signal, NULL) == -1)
        printf("Failed to set SIGUSR1 behavior\n");
    if (sigaction(SIGUSR2, &srv_signal, NULL) == -1)
        printf("Failed to set the SIGUSR2 behavior\n");
}

int main(void)
{
    //DONE! 1) Print the server PID. (CHANGE THE PRINTF BY PUTNBR AND PUTSTR);
    printf("PID: %d\n", getpid());
    //DONE! 3)Setup how the signals should behave and defining what each signal (SIGUSR1 = 1 and SIGUSR2 = 0) should do when received by the server.
    config_signals();
    /*signal(SIGUSR1, ft_listening_data);
    signal(SIGUSR2, ft_listening_data);*/


    //DONE! 2) Keep the program running "listening" for signals.
    while (1)
        pause();
}