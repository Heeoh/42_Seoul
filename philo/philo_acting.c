/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@Student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:11:08 by heson             #+#    #+#             */
/*   Updated: 2023/04/28 22:05:20 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pickup_a_fork(t_philo *p, pthread_mutex_t *fork)
{
	if (check_end(p))
		return (0);
	pthread_mutex_lock(fork);
	if (check_end(p))
	{
		pthread_mutex_lock(&p->info->lock);
		return (0);
	}
	printf("%d %d has taken a fork\n", get_timestamp(p->info->start_time), p->id + 1);
	return (1);
}

int	pickup(t_philo *p)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	first = p->l_fork;
	second = p->r_fork;
	if (p->id % 2 != 0)
	{
		first = p->r_fork;
		second = p->l_fork;
	}
	if (pickup_a_fork(p, first))
	{
		while (first == second && !check_end(p)); // umm.....
		if (pickup_a_fork(p, second))
			return (1);
	}
	putdown(p);
	return (0);
}

void	eating(t_philo *p)
{
	if (check_end(p))
		return ;
	pthread_mutex_lock(&p->info->lock);
	gettimeofday(p->last_eat, NULL);
	*(p->eat_cnt) -= 1;
	pthread_mutex_unlock(&p->info->lock);
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

	if (check_end(p))
		return ;
	gettimeofday(&cur, NULL);
	printf("%d %d is sleeping\n", get_timestamp(p->info->start_time), p->id + 1);
	custom_usleep(p->info->time_to_sleep, cur);
}

void	thinking(t_philo *p)
{
	if (check_end(p))
		return ;
	printf("%d %d is thinking\n", get_timestamp(p->info->start_time), p->id + 1);	
}