/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:34:08 by ebinjama          #+#    #+#             */
/*   Updated: 2024/01/22 17:22:38y ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

volatile t_eint	g_spid;

static void	sig_handler(int sig, siginfo_t *info, void *context);
static void	send_bits(pid_t spid, const char *message);
static void	send_null(pid_t spid);
static void	init_program(int c, char *v[], t_sigaction *sa);

int	main(int c, char *v[])
{
	t_sigaction	sa;

	init_program(c, v, &sa);
	send_bits(g_spid.value, v[2]);
	send_null(g_spid.value);
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
			if (usleep(500) == 0)
				werror(SERVER_TIMEOUT);
		}
		++message;
	}
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	//if ((sig == SIGUSR1 || sig == SIGUSR2) && info->si_pid != g_spid.value)
	//	return (werror(UNKNOWN_SERVER));
	if (sig == SIGUSR1)
		return ;
	if (sig == SIGUSR2)
		ft_putendl_fd(MESSAGE_SENT, STDOUT_FILENO);
}

void	init_program(int c, char *v[], t_sigaction *sa)
{
	g_spid = ft_atoi(v[1]);
	if (c != 3)
		werror(BAD_FORMAT);
	if (g_spid.error)
		werror(BAD_INPUT);
	if (g_spid.value <= 0)
		werror(EASTER_EGG);
	sa->sa_flags = SA_SIGINFO;
	sa->sa_sigaction = sig_handler;
	if (sigaction(SIGUSR1, sa, NULL) == -1)
		werror(BAD_SIGNAL);
	if (sigaction(SIGUSR2, sa, NULL) == -1)
		werror(BAD_SIGNAL);
}

void	send_null(pid_t spid)
{
	unsigned short	i;

	i = 0;
	while (i++ <= 7)
	{
		if (kill(spid, SIGUSR1) == -1)
			werror(BAD_SIGNAL);
		if (usleep(500) == 0)
			werror(SERVER_TIMEOUT);
	}
}
