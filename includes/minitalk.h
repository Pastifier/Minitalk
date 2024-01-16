/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebinjama <ebinjama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 09:28:26 by ebinjama          #+#    #+#             */
/*   Updated: 2024/01/16 22:08:55 by ebinjama         ###   ########.fr       */
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

typedef struct sigaction	t_sig;

/*----RECEIVER----*/
# define CHR 0
# define FOUND_ONE 1
# define BIT_COUNT 2
# define CPID 3

/*---STRUCT(S?)---*/

// Always declare as static
// to make use of auto-initialisation.
typedef struct s_sigchar
{
	volatile unsigned char	character;
	volatile short			bit_counter;
	volatile bool			flag;
}	t_sigchar;

#endif // !MINITALK_H