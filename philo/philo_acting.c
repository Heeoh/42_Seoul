/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:11:08 by heson             #+#    #+#             */
/*   Updated: 2023/04/28 17:35:19 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pickup(t_philo *p)
{
	int	is_odd;

	is_odd = p->id % 2;
	if (is_odd) // odd
		pthread_mutex_lock(p->l_fork);
	else
		pthread_mutex_lock(p->r_fork);
	printf("%d %d has taken a fork\n", get_timestamp(p->info->start_time), p->id + 1);
	if (is_odd)
		pthread_mutex_lock(p->r_fork);
	else
		pthread_mutex_lock(p->l_fork);
	printf("%d %d has taken a fork\n", get_timestamp(p->info->start_time), p->id + 1);
}

void	eating(t_philo *p)
{
	gettimeofday(p->last_eat, NULL);
	printf("%d %d is eating\n", get_timestamp(p->info->start_time), p->id);
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
	custom_usleep(p->info->time_to_eat, cur);
}

void	thinking(t_philo *p)
{
	printf("%d %d is thinking\n", get_timestamp(p->info->start_time), p->id + 1);	
}