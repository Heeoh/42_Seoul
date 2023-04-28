/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@Student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:11:08 by heson             #+#    #+#             */
/*   Updated: 2023/04/28 19:09:11 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pickup_a_fork(t_philo *p, pthread_mutex_t *fork)
{
	if (!p->info->is_end)
	{
		pthread_mutex_lock(fork);
		if (p->info->is_end)
		{
			pthread_mutex_unlock(fork);
			return (0);
		}
		printf("%d %d has taken a fork\n", get_timestamp(p->info->start_time), p->id + 1);
		return (1);
	}
	return (0);
}

int	pickup(t_philo *p)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (p->id % 2 == 0)
	{
		first = p->l_fork;
		second = p->r_fork;
	}
	else
	{
		first = p->r_fork;
		second = p->l_fork;
	}
	if (pickup_a_fork(p, first))
	{ 
		if (first != second && pickup_a_fork(p, second))
			return (1);
	}
	putdown(p);
	return (0);
}

void	eating(t_philo *p)
{
	gettimeofday(p->last_eat, NULL);
	*(p->eat_cnt) -= 1;
	printf("%d %d is eating\n", get_timestamp(p->info->start_time), p->id + 1);
	custom_usleep(p->info->time_to_eat, *(p->last_eat));
}

void	putdown(t_philo	*p)
{
	pthread_mutex_unlock(p->l_fork);
	pthread_mutex_unlock(p->r_fork);
}

void	sleeping(t_philo *p)
{
	t_timestamp	cur;

	gettimeofday(&cur, NULL);
	printf("%d %d is sleeping\n", get_timestamp(p->info->start_time), p->id + 1);
	custom_usleep(p->info->time_to_sleep, cur);
}

void	thinking(t_philo *p)
{
	printf("%d %d is thinking\n", get_timestamp(p->info->start_time), p->id + 1);	
}