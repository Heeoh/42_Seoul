/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:17:49 by heson             #+#    #+#             */
/*   Updated: 2023/01/26 16:52:49 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minitalk.h"

int g_prev_sig = 0;

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
	if (g_prev_sig == 0)
		kill(siginfo->si_pid, ONE);
	else
		kill(siginfo->si_pid, ZERO);
	g_prev_sig = !g_prev_sig;
}

void	init_sigaction(struct sigaction *sa)
{
	sa->sa_sigaction = signal_handler;
	sa->sa_flags = SA_SIGINFO;
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
		pause();
	return (0);
}
