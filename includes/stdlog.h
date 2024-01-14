/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdlog.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:32:23 by ebinjama          #+#    #+#             */
/*   Updated: 2024/01/14 10:06:18 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDLOG_H
# define STDLOG_H

# define RED "\x1b[31m"
# define DEF "\x1b[0m"

# define BAD_SIGNAL "Error: BAD SIGNAL"
# define BAD_INPUT "Input must be valid, habibi."
# define EASTER_EGG "You tryna crash your device habibi?"
# define BAD_FORMAT "Format:\n\t./client [PID] [message]"

void	werror(const char *error_message);
#endif // !STDLOG_H