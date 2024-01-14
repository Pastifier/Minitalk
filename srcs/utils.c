/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:59:21 by ebinjama          #+#    #+#             */
/*   Updated: 2024/01/14 16:20:04 by ebinjama         ###   ########.fr       */
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