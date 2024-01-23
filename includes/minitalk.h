/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:28:26 by ebinjama          #+#    #+#             */
/*   Updated: 2024/01/23 20:59:46 by ebinjama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <stdint.h>
# include <signal.h>
# include <stdbool.h>
# include "../libft/includes/libft.h"
# include "stdlog.h"

# define TRY_SPOT 1
# define SRV_INFO 0

# define CHR 0
# define COUNT 1

typedef volatile __CHAR32_TYPE__	t_univ;
typedef struct sigaction			t_sigaction;

void	wflush(const char *errmsg, pid_t cpid, void *c, void *i);
void	werror(const char *errmsg);

#endif // !MINITALK_H