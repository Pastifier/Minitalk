/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdlog.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:32:23 by ebinjama          #+#    #+#             */
/*   Updated: 2024/01/15 14:53:42 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDLOG_H
# define STDLOG_H

# define RED "\x1b[31m"
# define DEF "\x1b[0m"

# define BAD_SIGNAL "Error: BAD SIGNAL"
# define BAD_INPUT "Input must be valid, habibi."
# define EASTER_EGG "You tryna crash the device, habibi?"
# define BAD_FORMAT "Format:\n\t./client [PID] [message]"
# define BAD_SETUP "Error: Couldn't setup signal handler."

# define PRINT_VAR(VAR, MESSAGE)	ft_putstr_fd(RED, STDOUT_FILENO); \
									ft_putendl_fd(MESSAGE, STDOUT_FILENO); \
									ft_putnbr_fd(VAR, STDOUT_FILENO); \
									ft_putendl_fd(DEF, STDOUT_FILENO);
void	werror(const char *error_message);
#endif // !STDLOG_H