/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:17:53 by heson             #+#    #+#             */
/*   Updated: 2023/01/25 16:55:44 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minitalk.h"

int	g_send_cnt = 0;

void	signal_handler(int sig)
{
	static int	recv_cnt;

	if (sig == SIG_ACK)
		recv_cnt++;
	else if (sig == END)
	{
		if (recv_cnt == g_send_cnt)
			write(1, "OK\n", 3);
		else
			write(1, "ERROR\n", 6);
		g_send_cnt = 0;
		recv_cnt = 0;
	}
}

void	send_str(int server_pid, char *str)
{
	int					bit_i;

	g_send_cnt = 0;
	while (str && *str)
	{
		signal(END, signal_handler);
		bit_i = (1 << 7);
		while (bit_i > 0)
		{
			signal(SIG_ACK, signal_handler);
			if ((*str & bit_i) == 0)
				kill(server_pid, ZERO);
			else
				kill(server_pid, ONE);
			g_send_cnt++;
			bit_i >>= 1;
			pause();
		}
		str++;
		g_send_cnt = 0;
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
	return (0);
}
