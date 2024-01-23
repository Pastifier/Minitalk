/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 20:57:48 by ebinjama          #+#    #+#             */
/*   Updated: 2024/01/23 20:58:13 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	init_sigaction(t_sigaction *sa);
static void	sig_handler(int sig, siginfo_t *info, void *context);

int	main(int c, char *v[])
{
	struct sigaction	sa;

	init_sigaction(&sa);
	if (c > 1)
		ft_putendl_fd(UA, STDOUT_FILENO);
	(void)v;
	ft_putnbr_fd((int)getpid(), STDOUT_FILENO);
	ft_putendl_fd("", STDOUT_FILENO);
	while (true)
		pause();
	return (0);
}

void	sig_handler(int signal, siginfo_t *info, void *context)
{
	static volatile __CHAR32_TYPE__	c;
	static volatile unsigned short	i;

	(void)context;
	c |= ((signal == SIGUSR2) << (i));
	i++;
	if (i == 8 && c == 0)
	{
		i = 0;
		write(STDOUT_FILENO, "\n", 1);
		if (kill(info->si_pid, SIGUSR2) == -1)
			wflush(LOST_COMM, info->si_pid, (void *)&c, (void *)&i);
	}
	else if (i == 8)
	{
		write(STDOUT_FILENO, (const void *)&c, 1);
		c = 0;
		i = 0;
	}
}

void	init_sigaction(t_sigaction *sa)
{
	sa->sa_flags = SA_SIGINFO;
	sa->sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, sa, NULL) == -1)
		werror(BAD_SIGNAL);
	if (sigaction(SIGUSR2, sa, NULL) == -1)
		werror(BAD_SIGNAL);
}
