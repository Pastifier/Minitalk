/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:51:12 by ebinjama          #+#    #+#             */
/*   Updated: 2024/01/22 16:51:16 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	sig_handler(int signal);

int	main(int c, char *v[])
{
	if (c > 1)
		ft_putendl_fd(UA, STDOUT_FILENO);
	(void)v;
	ft_putnbr_fd((int)getpid(), STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
	if (signal(SIGUSR1, sig_handler) == SIG_ERR)
		werror(BAD_SIGNAL);
	if (signal(SIGUSR2, sig_handler) == SIG_ERR)
		werror(BAD_SIGNAL);
	while (true)
		pause();
	return (0);
}

static void	sig_handler(int signal)
{
	static volatile __CHAR32_TYPE__	c;
	static volatile unsigned short	i;

	c |= ((signal == SIGUSR2) << i);
	++i;
	if (i == 8)
	{
		write(STDOUT_FILENO, (const void *)&c, 1);
		c = 0;
		i = 0;
	}
}
