/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:17:53 by heson             #+#    #+#             */
/*   Updated: 2023/01/27 16:45:00 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minitalk.h"

// volatile sig_atomic_t lock = 0;
volatile sig_atomic_t flag = -1;

void	signal_handler(int sig)
{
	// lock = 1;
	flag = sig;
}

void	check_ack(int *recv_cnt, int *send_cnt, int send_sig)
{
	ft_printf("%d) ", flag - 30);
	(*recv_cnt)++;
	if (flag != send_sig)
	{
		write(1, "ERROR, send again\n", 18);
		send_cnt--;
		(*recv_cnt)--;
		flag = -1;
		return;
	}
	flag = -1;
}

int	send_bit(int server_pid, int bit, int *send_cnt)
{
	int	sig;

	if (bit == 0)
		sig = ZERO;
	else
		sig = ONE;
	ft_printf("(%d, ", sig - 30);
	(*send_cnt)++;
	kill(server_pid, sig);
	return (sig);
}

void	init_sigaction(struct sigaction *sa)
{
	sa->sa_handler = signal_handler;
	sigemptyset(&(sa->sa_mask));
	sigaddset(&(sa->sa_mask), SIGUSR1);
	sigaddset(&(sa->sa_mask), SIGUSR2);
	sa->sa_flags = SA_RESTART;
}

void	send_str(int server_pid, char *str, int *send_cnt, int *recv_cnt)
{
	int					bit_i;
	struct sigaction	sa;
	int 				send_sig;

	init_sigaction(&sa);
	while (str)
	{
		ft_printf("\n%c ", *str);
		bit_i = (1 << 8);
		while (bit_i > 1)
		{
			sigaction(ZERO, &sa, 0);
			sigaction(ONE, &sa, 0);
			if (flag >= 0)
				check_ack(recv_cnt, send_cnt, send_sig);
			bit_i >>= 1;
			send_sig = send_bit(server_pid, (*str & bit_i), send_cnt);
			pause();
		}
		check_ack(recv_cnt, send_cnt, send_sig);
		if (!*str)
			break;
		str++;
	}
}

int	main(int ac, char *av[])
{
	int	server_pid;
	int send_cnt;
	int recv_cnt;

	if (ac != 3)
		return (0);
	server_pid = atoi(av[1]);
	send_cnt = 0;
	recv_cnt = 0;
	ft_printf("client(%d) is connecting to server(%d) ...\n", getpid(), server_pid);
	send_str(server_pid, av[2], &send_cnt, &recv_cnt);

	if (recv_cnt != send_cnt)
		ft_printf("ERROR\n");
	else
		ft_printf("SUCCESS\n");
	return (0);
}
