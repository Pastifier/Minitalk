/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:57:10 by ebinjama          #+#    #+#             */
/*   Updated: 2024/01/22 16:52:34 by ebinjama         ###   ########.fr       */
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

	while (*message)
	{
		i = -1;
		while (++i <= 7)
		{
			if (((*message >> i) & 1))
			{
				if (kill(pid, SIGUSR2) == -1)
					werror(BAD_SIGNAL);
			}
			else if (kill(pid, SIGUSR1) == -1)
				werror(BAD_SIGNAL);
			usleep(200);
		}
		++message;
	}
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
