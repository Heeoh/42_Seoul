/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@Student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:35:36 by heson             #+#    #+#             */
/*   Updated: 2023/04/27 18:47:57 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

int get_timestamp(struct timeval start)
{
    struct timeval  cur;
    int     msec;

    gettimeofday(&cur ,NULL);
    msec = (cur.tv_sec - start.tv_sec) * 1000 + (cur.tv_usec - start.tv_usec) / 1000;
    return (msec);
}

int	check_die(t_dining_table *table)
{
	int	i;
    int hungry_time;

	i = table->philo_num;
	pthread_mutex_lock(&table->lock);
	while (--i >= 0)
	{
		hungry_time = get_timestamp(table->last_eat_times[i]);
		if (table->states[i] != EATING && hungry_time >= table->time_info[TIME_2_DIE])
		{
			printf("%d %d is died\n", get_timestamp(table->start_time), i + 1);
			return (1);
		}
	}
	pthread_mutex_unlock(&table->lock);
    return (0);
}

void	pickup(int id, int *state, t_dining_table *table)
{
	int	left;
	int right;

	left = (id + table->philo_num - 1) % table->philo_num;
	right = (id + 1) % table->philo_num;
	if (id == right && id == left)
		return ;
	pthread_mutex_lock(&table->lock);
	if (*state == THINKING
		&& table->states[left] != EATING && table->states[right] != EATING)
	{
		printf("%d %d has taken a fork\n", get_timestamp(table->start_time), id + 1);
		printf("%d %d has taken a fork\n", get_timestamp(table->start_time), id + 1);
		*state = EATING;
		return ;
	}
	pthread_mutex_unlock(&table->lock);
}

void	eating(int id, int eating_time, t_dining_table *table)
{
	gettimeofday(&(table->last_eat_times[id]), NULL);
	printf("%d %d is eating\n", get_timestamp(table->start_time), id + 1);
	pthread_mutex_unlock(&table->lock);
	usleep(eating_time * 1000);
}

void	sleeping(int id, int *state, int sleeping_time, t_dining_table *table)
{
	pthread_mutex_lock(&table->lock);
	*state = SLEEPING;
	printf("%d %d is sleeping\n", get_timestamp(table->start_time), id + 1);
	pthread_mutex_unlock(&table->lock);
	usleep(sleeping_time * 1000);
}

void	thinking(int id, int *state, t_timestamp start)
{
	*state = THINKING;
	printf("%d %d is thinking\n", get_timestamp(start), id + 1);
}