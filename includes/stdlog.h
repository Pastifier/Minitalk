/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdlog.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:32:23 by ebinjama          #+#    #+#             */
/*   Updated: 2024/01/22 17:18:13 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDLOG_H
# define STDLOG_H

# define RED "\x1b[31m"
# define GRN "\x1b[32m"
# define DEF "\x1b[0m"

# define BAD_SIGNAL "Error: BAD SIGNAL"
# define BAD_INPUT "Input must be valid, habibi."
# define EASTER_EGG "You tryna crash the device, habibi?"
# define BAD_FORMAT "Format:\n\t./client [PID] [message]"
# define BAD_SETUP "Error: Couldn't setup signal handler."
# define UA RED"You do realise arguments do nothing, right?"DEF
# define MESSAGE_SENT GRN"Message recieved by server"DEF
# define UNKNOWN_SERVER "Received communication from unknown source"
# define SERVER_TIMEOUT "Server took too long."

void	werror(const char *error_message);
#endif // !STDLOG_H