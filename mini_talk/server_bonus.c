/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:34:15 by heson             #+#    #+#             */
/*   Updated: 2023/01/24 19:09:49 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minitalk.h"

void	signal_handler(int sig)
{
	static int	cnt;
	static char	my_char;
	int			bit;

	bit = 1;
	if (sig == SIGUSR1)
		bit = 0;
	my_char = (my_char << 1) | bit;
	cnt++;
	if (cnt >= 8)
	{
		if (write(1, &my_char, 1))
			my_char = 0;
		cnt = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
