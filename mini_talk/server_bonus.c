/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:17:49 by heson             #+#    #+#             */
/*   Updated: 2023/01/24 21:15:36 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minitalk.h"

void	signal_handler(int sig, siginfo_t *siginfo, void *p)
{
	static int	cnt;
	static char	my_char;
	int			bit;

	p = 0;
	bit = 1;
	if (sig == SIGUSR1)
		bit = 0;
	my_char = (my_char << 1) | bit;
	cnt++;
	kill(siginfo->si_pid, sig);
	if (cnt >= 8)
	{
		if (write(1, &my_char, 1))
			my_char = 0;
		cnt = 0;
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
