/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uviana-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 19:28:40 by uviana-a          #+#    #+#             */
/*   Updated: 2023/08/18 19:28:42 by uviana-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>

size_t	ft_strlen(const char *s);

char	*ft_strjoin_mod(char *s1, char *s2);

void	ft_putstr_fd(char *s, int fd);

void	ft_putnbr(unsigned int pid);

int		ft_atoi(const char *nptr);

#endif
