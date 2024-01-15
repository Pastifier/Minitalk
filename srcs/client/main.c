/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:57:10 by ebinjama          #+#    #+#             */
/*   Updated: 2024/01/15 11:01:01 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	send_bits(pid_t pid, const char *message);
static void	validate_input(int c, char *v[]);

int	main(int c, char *v[])
{
	validate_input(c, v);
	send_bits(ft_atoi(v[1]).value, v[2]);
	return (0);
}

void	send_bits(pid_t pid, const char *message)
{
	short	i;
	(void)pid; // For now
	if (!*message)
		return ;
	while (*message)
	{
		i = -1;
		while (++i <= 7)
		{
			if (((*message << i) & 1) == 0)
				ft_putendl_fd("0", STDOUT_FILENO);
				//if (kill(pid, SIGUSR1) == -1)
				//	werror(BAD_SIGNAL);
			if (((*message << i) & 1) == 1)
				ft_putendl_fd("1", STDOUT_FILENO);
				//if (kill(pid, SIGUSR2) == -1)
				//	werror(BAD_SIGNAL);
			usleep(150);
		}
		++message;
	}
	//while (++i <= 14)
	//	if (kill(pid, SIGUSR1) == -1)
	//		werror(BAD_SIGNAL);
}

void	validate_input(int c, char *v[])
{
	if (c != 3)
		werror(BAD_FORMAT);
	if (ft_atoi(v[1]).error)
		werror(BAD_INPUT);
	if (ft_atoi(v[1]).value <= 0)
		werror(EASTER_EGG);
}