/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:34:15 by heson             #+#    #+#             */
/*   Updated: 2023/01/25 16:50:07 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minitalk.h"

void	signal_handler(int sig)
{
	static int	recv_cnt;
	static char	ch;
	int			bit;

	bit = 1;
	bit = (sig == ONE);
	ch = (ch << 1) | bit;
	recv_cnt++;
	if (recv_cnt >= 8)
	{
		write(1, &ch, 1);
		ch = 0;
		recv_cnt = 0;
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
