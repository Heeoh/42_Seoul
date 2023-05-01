/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:13:29 by heson             #+#    #+#             */
/*   Updated: 2023/05/01 16:16:47 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <limits.h>

static long long	time_2_ms(t_timestamp time)
{
	long long	msec;

	msec = time.tv_sec * 1000;
	msec += time.tv_usec / 1000;
	return (msec);
}

long long	get_timestamp(t_timestamp cur, t_timestamp prev)
{
	return (time_2_ms(cur) - time_2_ms(prev));
}

void	custom_usleep(long long wait_time, t_timestamp prev)
{
	long long	time_gap;
	t_timestamp	cur;

	usleep(wait_time * 1000 * 0.8);
	while (1)
	{
		gettimeofday(&cur, NULL);
		time_gap = get_timestamp(cur, prev);
		if (time_gap >= wait_time)
			break ;
		usleep(50);
	}
}

void	do_free(t_table *table, t_philo *philos, pthread_t *tid)
{
	if (table->forks)
		free(table->forks);
	if (table->eat_counts)
		free(table->eat_counts);
	if (table->last_eats)
		free(table->last_eats);
	if (philos)
		free(philos);
	if (tid)
		free(tid);
}

int	ft_atoi(const char *str)
{
	char				*p;
	int					sign;
	unsigned long long	absolute_num;

	p = (char *)str;
	sign = 1;
	while (*p && (*p == ' ' || (9 <= *p && *p <= 13)))
		p++;
	if (*p == '-' || *p == '+')
	{
		if (*p == '-')
			sign = -1;
		p++;
	}
	absolute_num = 0;
	while (*p && '0' <= *p && *p <= '9')
	{
		absolute_num = absolute_num * 10 + (*p - '0');
		if (sign == 1 && absolute_num >= LLONG_MAX)
			return (-1);
		if (sign == -1 && absolute_num > LLONG_MAX)
			return (0);
		p++;
	}
	return (absolute_num * sign);
}
