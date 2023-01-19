/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:34:17 by heson             #+#    #+#             */
/*   Updated: 2023/01/20 01:59:05 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/minitalk.h"

void convert2binary_n_send(int server_pid, char ch)
{
	for (int i=(1 << 7); i > 0; i >>= 1) {
		if ((ch & i) == 0) {
			// printf("send SIGSUR1\n");
			kill(server_pid, SIGUSR1);
		}
		else {
			// printf("send SIGSUR2\n");
			kill(server_pid, SIGUSR2);
		}
		usleep(100);
	}
}

int main(int ac, char *av[]) // ac=3. av[1]=server pid, av[2]=str
{
	int server_pid;
	int str_len;

	// communicate to server, send the str as parameter
	if (ac == 3) {
		server_pid = atoi(av[1]);  
		ft_printf("client is connecting to %d ...\n", server_pid);
		str_len = ft_strlen(av[2]);
		for (int i=0; i<str_len; i++)
			convert2binary_n_send(server_pid, av[2][i]);
		convert2binary_n_send(server_pid, '\n');

	}
	
}