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

int main(void)
{
    //DONE! 1) Print the server PID. (CHANGE THE PRINTF BY PUTNBR AND PUTSTR);
    printf("PID: %d\n", getpid());
    //2) Define what the each signal (SIGUSR1 = 1 and SIGUSR2 = 0) should do when received by the server.
    signal(SIGUSR1, listening_data);
    signal(SIGUSR2, listening_data);
    while (1)
    {     }
}

