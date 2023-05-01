/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:11:08 by heson             #+#    #+#             */
/*   Updated: 2023/05/01 16:08:14 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pickup(t_philo *p)
{
	if (!check_end(p->info) && pthread_mutex_lock(p->l_fork) == 0)
	{
		print_state(p->id, p->info, "has taken a fork");
		while (p->l_fork == p->r_fork && !check_end(p->info))
			;
		if (!check_end(p->info) && pthread_mutex_lock(p->r_fork) == 0)
		{
			print_state(p->id, p->info, "has taken a fork");
			return (SUCCESS);
		}
	}
	putdown(p);
	return (FAIL);
}

void	eating(t_philo *p)
{
	if (check_end(p->info))
		return ;
	pthread_mutex_lock(&p->info->lock);
	gettimeofday(p->last_eat, NULL);
	if (*(p->eat_cnt) > 0)
		*(p->eat_cnt) -= 1;
	pthread_mutex_unlock(&p->info->lock);
	print_state(p->id, p->info, "is eating");
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

	if (check_end(p->info))
		return ;
	gettimeofday(&cur, NULL);
	print_state(p->id, p->info, "is sleeping");
	custom_usleep(p->info->time_to_sleep, cur);
}

void	thinking(t_philo *p)
{
	if (check_end(p->info))
		return ;
	print_state(p->id, p->info, "is thinking");
}
