/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:13:29 by heson             #+#    #+#             */
/*   Updated: 2023/04/28 16:20:59 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_timestamp(t_timestamp prev)
{
	t_timestamp	cur;
	int			msec;

	gettimeofday(&cur, NULL);
	msec = (cur.tv_sec - prev.tv_sec) * 1000 + (cur.tv_usec - prev.tv_usec) / 1000;
	return (msec);
}

void	custom_usleep(int wait_time, t_timestamp prev)
{
	int	time_gap;

	usleep(wait_time * 1000 * 0.8);
	while (1)
	{
		time_gap = get_timestamp(prev);
		if (time_gap >= wait_time)
			break ;
		usleep(200);
	}
}
