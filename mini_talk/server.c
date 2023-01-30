/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:32:02 by heson             #+#    #+#             */
/*   Updated: 2023/01/30 11:49:46 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minitalk.h"

void	signal_handler(int sig)
{
	static int	recv_cnt;
	static char	ch;
	int			bit;

	bit = (sig == ONE_SIG);
	ch = (ch << 1) | bit;
	recv_cnt++;
	if (recv_cnt == 8)
	{
		if (ch)
			write(1, &ch, 1);
		else
			write(1, "\n", 1);
		ch = 0;
		recv_cnt = 0;
	}
}

void	init_sigaction(struct sigaction *sa)
{
	sa->sa_handler = signal_handler;
	sigemptyset(&(sa->sa_mask));
	sigaddset(&(sa->sa_mask), SIGUSR1);
	sigaddset(&(sa->sa_mask), SIGUSR2);
	sa->sa_flags = SA_RESTART;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	init_sigaction(&sa);
	pid = getpid();
	ft_printf("%d\n", pid);
	while (1)
	{
		sigaction(ZERO_SIG, &sa, 0);
		sigaction(ONE_SIG, &sa, 0);
		pause();
	}
	return (0);
}
