/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:59:21 by ebinjama          #+#    #+#             */
/*   Updated: 2024/01/23 00:26:55 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	werror(const char *error_message)
{
	short	i;

	ft_putstr_fd(RED, STDERR_FILENO);
	ft_putendl_fd((char *)error_message, STDERR_FILENO);
	ft_putstr_fd("Aborting", STDERR_FILENO);
	i = -1;
	while (++i < 3)
	{
		ft_putchar_fd('.', STDERR_FILENO);
		usleep(500000);
	}
	ft_putendl_fd(DEF, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	wflush(const char *errmsg, pid_t cpid, void *c, void *i)
{
	__CHAR32_TYPE__	*flush_c;
	unsigned int	*flush_i;
	int				fd;

	flush_c = (__CHAR32_TYPE__ *)c;
	flush_i = (unsigned int *)i;
	if (*flush_c || *flush_i)
	{
		fd = STDOUT_FILENO;
		if (*errmsg)
		{
			fd = STDERR_FILENO;
			ft_putstr_fd(RED, fd);
			ft_putstr_fd((char *)errmsg, fd);
			ft_putnbr_fd((int)cpid, fd);
			ft_putendl_fd("", fd);
		}
		else
			ft_putstr_fd(GRN, fd);
		ft_putstr_fd("Waiting for next message...", fd);
		ft_putendl_fd(DEF, fd);
	}
	*flush_i = 0;
	*flush_c = 0;
}
