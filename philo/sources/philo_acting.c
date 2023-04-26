/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@Student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:35:36 by heson             #+#    #+#             */
/*   Updated: 2023/04/26 17:59:24 by heson            ###   ########.fr       */
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

void    check_die(int id, int *state, int time, struct timeval start)
{
    int hungry_time;

    hungry_time = get_timestamp(start);
    if (hungry_time >= time)
        *state = DIED;
	printf("%d %d is died\n", get_timestamp(start), id);
}

void	pickup(pthread_mutex_t *lock, int id, int *state, int philo_n, struct timeval start)
{
	int	left;
	int right;

	left = (id + philo_n - 1) % philo_n;
	right = (id + 1) % philo_n;
	pthread_mutex_lock(lock);
	if (state[id] == THINKING 
		&& state[left] != EATING && state[right] != EATING)
	{
		printf("%d %d has taken a fork\n", get_timestamp(start), id);
		printf("%d %d has taken a fork\n", get_timestamp(start), id);
		state[id] = EATING;
	}
	pthread_mutex_unlock(lock);
}

void	eating(int id, int time, struct timeval start)
{
	printf("%d %d is eating\n", get_timestamp(start), id);
	usleep(time);
}

void	sleeping(int id, int *state, int time, struct timeval start)
{
	*state = SLEEPING;
	printf("%d %d is sleeping\n", get_timestamp(start), id);
	usleep(time);
}

void	thinking(int id, int *state, struct timeval start)
{
	*state = THINKING;
	printf("%d %d is thinking\n", get_timestamp(start), id);
}