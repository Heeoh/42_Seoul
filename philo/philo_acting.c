/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:11:08 by heson             #+#    #+#             */
/*   Updated: 2023/04/29 02:12:18 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pickup(t_philo *p)
{
	pthread_mutex_t	*side_forks[2];
	int				i;

	side_forks[0] = p->l_fork;
	side_forks[1] = p->r_fork;
	if (p->id % 2 != 0)
	{
		side_forks[0] = p->r_fork;
		side_forks[1] = p->l_fork;
	}
	i = -1;
	while (++i < 2 && !check_end(p))
	{
		while (i == 1 && side_forks[0] == side_forks[1] && !check_end(p))
			;
		pthread_mutex_lock(side_forks[i]);
		if (check_end(p))
		{
			putdown(p);
			return (FAIL);
		}
		printf("%d %d has taken a fork\n",
			get_timestamp(p->info->start_time), p->id + 1);
	}
	return (SUCCESS);
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
	printf("%d %d is thinking\n",
		get_timestamp(p->info->start_time), p->id + 1);
}
