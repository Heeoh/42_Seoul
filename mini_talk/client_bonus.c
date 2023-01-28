/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:17:53 by heson             #+#    #+#             */
/*   Updated: 2023/01/27 07:05:45 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minitalk.h"

int	g_signal = 0;

void	ack_signal_handler(int sig)
{
	if (g_prev_ack < 0)
		g_prev_ack = sig;
	else if (g_prev_ack == sig)
		write(1, "error\n", 6);
	g_prev_ack = sig;
	recv_cnt++;
}

void	send_bit(int server_pid, int bit)
{
	if (bit == 0)
		kill(server_pid, ZERO);
	else
		kill(server_pid, ONE);
	send_cnt++;
	usleep(100);
}

void	send_str(int server_pid, char *str)
{
	int	bit_i;

	while (str && *str)
	{
		bit_i = (1 << 7);
		ft_printf("\n%c ", *str);
		while (bit_i > 0)
		{
			signal(ZERO, ack_signal_handler);
			signal(ONE, ack_signal_handler);
			send_bit(server_pid, (*str & bit_i));
			bit_i >>= 1;
			pause();
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
