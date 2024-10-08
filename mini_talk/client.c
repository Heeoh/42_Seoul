/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:31:36 by heson             #+#    #+#             */
/*   Updated: 2023/01/29 15:09:58 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minitalk.h"

void	send_bit(int server_pid, int bit)
{
	if (bit == 0)
		kill(server_pid, ZERO_SIG);
	else
		kill(server_pid, ONE_SIG);
	usleep(100);
}

void	send_str(int server_pid, char *str)
{
	int	bit_i;

	while (str)
	{
		bit_i = (1 << 7);
		while (bit_i > 0)
		{
			send_bit(server_pid, (*str & bit_i));
			bit_i >>= 1;
		}
		if (*str == '\0')
			break ;
		str++;
	}
}

int	main(int ac, char *av[])
{
	int	server_pid;

	if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);
		if (server_pid <= 0)
			return (0);
		ft_printf("client is connecting to server(%d) ...\n", server_pid);
		send_str(server_pid, av[2]);
	}
	return (0);
}
