/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 01:12:04 by heson             #+#    #+#             */
/*   Updated: 2023/01/25 16:53:28 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <signal.h>			// signal
# include <unistd.h>
# include "../library/libft/libft.h"
# include "../library/printf/headers/ft_printf.h"

# define ZERO SIGUSR1
# define ONE SIGUSR2

# define END SIGUSR1
# define SIG_ACK SIGUSR1

#endif
