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

static void	off_handler(pid_t, volatile t_sigchar *);
static void	on_handler(pid_t, volatile t_sigchar *);
static void	sig_handler(int, siginfo_t *, void *);

int main(void)
{
	struct sigaction sa;

	ft_putendl_fd(ft_itoa((int)getpid()), STDOUT_FILENO);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = NULL;
	sa.sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
		werror(BAD_SETUP);
	while (true)
		pause();
	return (0);
}

void off_handler(pid_t cpid, volatile t_sigchar *sc)
{
	(void)cpid;
	sc->bit_counter = (sc->bit_counter + 1);
	if (sc->bit_counter == 7 && sc->flag == 1)
	{
		ft_putchar_fd(sc->character, STDOUT_FILENO);
		sc->flag = 0;
		sc->character = 0;
		sc->bit_counter = 0;
	}
}

void on_handler(pid_t cpid, volatile t_sigchar *sc)
{
	(void)cpid;
	sc->character += (1 << sc->bit_counter);
	sc->bit_counter = (sc->bit_counter + 1);
	sc->flag = 1;
	if (sc->bit_counter == 7)
	{
		ft_putchar_fd(sc->character, STDOUT_FILENO);
		sc->character = 0;
		sc->bit_counter = 0;
		sc->flag = 0;
	}
}

void sig_handler(int sig, siginfo_t *info, void *context)
{
	static volatile t_sigchar	sc;

	(void)context;
	if (sig == SIGUSR1)
		on_handler(info->si_pid, &sc);
	else if (sig == SIGUSR2)
		off_handler(info->si_pid, &sc);
}