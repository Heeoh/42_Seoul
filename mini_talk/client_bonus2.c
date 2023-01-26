/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:17:53 by heson             #+#    #+#             */
/*   Updated: 2023/01/26 21:35:58 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minitalk.h"

int	g_signal = 0;
int send_cnt = 0;
int recv_cnt = 0;

void	signal_handler(int sig)
{
	if (sig != ONE) return;
	recv_cnt++;
	g_signal = 1;
}

void	send_bit(int server_pid, int bit)
{
	if (bit == 0)
		kill(server_pid, ZERO);
	else
		kill(server_pid, ONE);
	send_cnt++;
	g_signal = 0;
}

void	init_sigaction(struct sigaction *sa)
{
	sa->sa_handler = signal_handler;
	sigemptyset(&(sa->sa_mask));
	sigaddset(&(sa->sa_mask), SIGUSR1);
	sigaddset(&(sa->sa_mask), SIGUSR2);
	sa->sa_flags = SA_RESTART;
}

void	send_str(int server_pid, char *str)
{
	int	bit_i;
	struct sigaction	sa;

	init_sigaction(&sa);
	while (str && *str)
	{
		bit_i = (1 << 7);
		while (1)
		{
			sigaction(ZERO, &sa, 0);
			sigaction(ONE, &sa, 0);
			send_bit(server_pid, (*str & bit_i));
			bit_i >>= 1;
			if (bit_i <= 0)
				break;
			while (!g_signal);
		}
		str++;
	}
}

int	main(int ac, char *av[])
{
	int	server_pid;

	if (ac == 3)
	{
		server_pid = atoi(av[1]);
		ft_printf("client(%d) is connecting to %d ...\n", getpid(), server_pid);
		send_str(server_pid, av[2]);
	}
	if (recv_cnt != send_cnt)
		ft_printf("error\n");
	return (0);
}
