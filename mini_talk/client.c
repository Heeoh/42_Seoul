/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:34:17 by heson             #+#    #+#             */
/*   Updated: 2023/01/20 03:41:03 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minitalk.h"

void	convert2binary_n_send(int server_pid, char ch)
{
	int	i;

	i = (1 << 8);
	while (i > 0)
	{
		if ((ch & i) == 0)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		i >>= 1;
	}
}

int	main(int ac, char *av[])
{
	int	server_pid;
	int	str_len;
	int	i;

	if (ac == 3)
	{
		server_pid = atoi(av[1]);
		ft_printf("client is connecting to %d ...\n", server_pid);
		str_len = ft_strlen(av[2]);
		i = 0;
		while (i < str_len)
			convert2binary_n_send(server_pid, av[2][i++]);
		convert2binary_n_send(server_pid, '\n');
	}
	return (0);
}
