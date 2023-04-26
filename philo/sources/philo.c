/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@Student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:56:26 by heson             #+#    #+#             */
/*   Updated: 2023/04/26 17:58:51 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"
#include <stdlib.h> //atoi 

void	init(int ac, char *av[], int **info, int **state)
{
	int	i;

	*info = (int *)malloc(sizeof(int) * (ac - 1));
	i = 0;
	while (++i < ac)
		(*info)[i - 1] = atoi(av[i]);
	*state = (int *)malloc(sizeof(int) * (*info)[PHILO_N]);
	memset(*state, THINKING, (*info)[PHILO_N] * sizeof(int));
	// parsing error
}

void	*philosopher(void *arg)
{
	int				id;
	int				*state;
	int				*philo_info;
	pthread_mutex_t	*lock;
	struct timeval	start;
	

	id = ((t_thread_info *)arg)->id;
	state = ((t_thread_info *)arg)->state;
	philo_info = ((t_thread_info *)arg)->philo_info;
	lock = ((t_thread_info *)arg)->lock;
	start = ((t_thread_info *)arg)->start_time;
	while (1)
	{
		check_die(id, state + id, philo_info[TIME_2_DIE], start);
		if (state[id] == DIED)
			return (0);
		pickup(lock, id, state, philo_info[PHILO_N], start);
		if (state[id] != EATING)
			continue ;
		eating(id, philo_info[TIME_2_EAT], start);
		sleeping(id, state + id, philo_info[TIME_2_SLEEP], start);
		thinking(id, state + id, start);
	}
}

int	main(int ac, char *av[])
{
	if (!(ac == 5 || ac == 6))
	{
		printf("arguments error\n");
		return (1);
	}

	int	*info;
	int	*state;
	pthread_mutex_t mutex_lock;
	pthread_t	tid;
	t_thread_info	*thread_info;
	struct timeval	start;
	int	i;
	
	init(ac, av, &info, &state);
	if (gettimeofday(&start, NULL) == -1)
		return (1);
	pthread_mutex_init(&mutex_lock, NULL);
	i = -1;
	while (++i < info[PHILO_N])
	{
		thread_info = (t_thread_info *)malloc(sizeof(t_thread_info));
		thread_info->id = i;
		thread_info->lock = &mutex_lock;
		thread_info->philo_info = info;
		thread_info->state = state;
		thread_info->start_time = start;
		pthread_create(&tid, NULL, philosopher, (void *)thread_info);
	}
	i = -1;
	while (++i < info[PHILO_N])
		pthread_join(tid, NULL);

	free(info);
	free(state);
}