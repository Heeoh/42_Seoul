/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:17:49 by heson             #+#    #+#             */
/*   Updated: 2023/01/25 16:52:57 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minitalk.h"

void	signal_handler(int sig, siginfo_t *siginfo, void *p)
{
	static int	recv_cnt;
	static char	ch;
	int			bit;

	p = 0;
	bit = (sig == ONE);
	ch = (ch << 1) | bit;
	recv_cnt++;
	kill(siginfo->si_pid, SIG_ACK);
	if (recv_cnt >= 8)
	{
		write(1, &ch, 1);
		ch = 0;
		recv_cnt = 0;
		kill(siginfo->si_pid, END);
	}
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
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
