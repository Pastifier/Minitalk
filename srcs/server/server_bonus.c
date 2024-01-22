/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:50:47 by ebinjama          #+#    #+#             */
/*   Updated: 2024/01/22 17:21:44 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	init_sigaction(t_sigaction *sa,
				void (*f)(int, siginfo_t *, void *));
static void	sig_handler(int sig, siginfo_t *info, void *context);

int	main(int c, char *v[])
{
	struct sigaction	sa;

	init_sigaction(&sa, &sig_handler);
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
	c |= ((signal == SIGUSR2) << i);
	++i;
	if (i == 8 && (c & 0xFF) == 0)
	{
		i = 0;
		if (kill(info->si_pid, SIGUSR2) == -1)
			werror(BAD_SIGNAL);
	}
	else if (i == 8)
	{
		write(STDOUT_FILENO, (const void *)&c, 1);
		c = 0;
		i = 0;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		werror(BAD_SIGNAL);
}

void	init_sigaction(t_sigaction *sa, void (*f)(int, siginfo_t *, void *))
{
	sa->sa_flags = SA_SIGINFO;
	sa->sa_sigaction = *f;
	if (sigaction(SIGUSR1, sa, NULL) == -1)
		werror(BAD_SIGNAL);
	if (sigaction(SIGUSR2, sa, NULL) == -1)
		werror(BAD_SIGNAL);
}
