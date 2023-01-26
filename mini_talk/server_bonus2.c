/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:17:49 by heson             #+#    #+#             */
/*   Updated: 2023/01/26 21:37:09 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minitalk.h"

int	g_signal = 0;

void	signal_handler(int sig, siginfo_t *siginfo, void *p)
{
	static int	recv_cnt;
	static char	ch;
	int			bit;

	p = 0;
	bit = (sig == ONE);
	ch = (ch << 1) | bit;
	recv_cnt++;
	if (recv_cnt >= 8)
	{
		write(1, &ch, 1);
		ch = 0;
		recv_cnt = 0;
	}
	kill(siginfo->si_pid, sig);
}

void	init_sigaction(struct sigaction *sa)
{
	sa->sa_sigaction = signal_handler;
	sigemptyset(&(sa->sa_mask));
	sigaddset(&(sa->sa_mask), SIGUSR1);
	sigaddset(&(sa->sa_mask), SIGUSR2);
	sa->sa_flags = SIGINFO | SA_RESTART;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

    init_sigaction(&sa);
	pid = getpid();
	ft_printf("%d\n", pid);
	sigaction(ZERO, &sa, 0);
	sigaction(ONE, &sa, 0);
	while (1)
	{
		if (!g_signal)
			continue;
		g_signal = 0;
	}
	return (0);
}
