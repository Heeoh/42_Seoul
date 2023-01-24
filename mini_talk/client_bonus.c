/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:17:53 by heson             #+#    #+#             */
/*   Updated: 2023/01/24 21:44:45 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minitalk.h"

void	signal_handler(int sig, siginfo_t *siginfo, void *cnt)
{
	if (siginfo->si_signo == sig)
		ft_printf("sane");
	if (sig == SIGUSR1) {
		(*(int*)cnt)++;
		ft_printf("%d\n", *(int*)cnt);
	}
}

void	init_sigaction(struct sigaction *sa)
{
	sa->sa_sigaction = signal_handler;
	sa->sa_flags = SA_SIGINFO;
}

void	convert2binary_n_send(int server_pid, char ch)
{
	int					i;
	struct sigaction	sa;
	int					cnt;

	cnt = 0;
	init_sigaction(&sa);
	sigaction(SIGUSR1, &sa, (void*)&cnt);
	i = (1 << 7);
	while (i > 0)
	{
		if ((ch & i) == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		i >>= 1;
	}
	if (cnt < 8)
		ft_printf("error\n");
}

int	main(int ac, char *av[])
{
	int	server_pid;
	int	str_len;
	int	i;

	if (ac == 3)
	{
		server_pid = atoi(av[1]);
		ft_printf("client(%d) is connecting to %d ...\n", getpid(), server_pid);
		str_len = ft_strlen(av[2]);
		i = 0;
		while (i < str_len)
			convert2binary_n_send(server_pid, av[2][i++]);
	}
	return (0);
}
