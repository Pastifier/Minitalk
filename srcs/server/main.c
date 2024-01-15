/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:50:14 by ebinjama          #+#    #+#             */
/*   Updated: 2024/01/14 16:29:48by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static volatile int	g_receiver[4] = { 0 };

static void	off_handler(void);
static void	on_handler(void);
static void	sig_handler(int, siginfo_t *, void *);

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr_fd(g_receiver[FOUND_ONE], STDOUT_FILENO);
	ft_putendl_fd(ft_itoa((int)getpid()), STDOUT_FILENO);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = NULL;
	sa.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		werror(BAD_SIGNAL);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		werror(BAD_SIGNAL);
	while (true)
		;
	return (0);
}

void	off_handler(void)
{
	ft_putchar_fd('0', STDOUT_FILENO);
	g_receiver[CHR_COUNT] += 1;
	if (g_receiver[CHR_COUNT] == 7 && g_receiver[FOUND_ONE] == 1)
	{
		ft_putchar_fd(g_receiver[CHR], STDOUT_FILENO);
		g_receiver[FOUND_ONE] = 0;
		g_receiver[CHR] = 0;
	}
}

void	on_handler(void)
{
	ft_putchar_fd('1', STDOUT_FILENO);
	g_receiver[CHR] += (1 << g_receiver[CHR_COUNT]);
	g_receiver[CHR_COUNT] += 1;
	g_receiver[FOUND_ONE] = 1;
	if (g_receiver[CHR_COUNT] == 7)
	{
		ft_putchar_fd(g_receiver[CHR], STDOUT_FILENO);
		g_receiver[CHR] = 0;
	}
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	g_receiver[CPID] = (int)(info->si_pid);
	if (sig == SIGUSR1)
		off_handler();
	else if (sig == SIGUSR2)
		on_handler();
}