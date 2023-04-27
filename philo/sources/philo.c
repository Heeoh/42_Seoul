/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@Student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:56:26 by heson             #+#    #+#             */
/*   Updated: 2023/04/27 18:52:57 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"
#include <stdlib.h> //atoi 

void	init(int ac, char *av[], t_dining_table *table)
{
	int	i;

	// parsing error
	table->philo_num = atoi(av[1]);
	table->time_2_die = atoi(av[2]);
	table->time_2_eat = atoi(av[3]);
	table->time_2_sleep = atoi(av[4]);
	table->minimum_eat = -1;
	if (ac == 6)
		table->minimum_eat = atoi(av[5]);

	table->states = (int *)malloc(sizeof(int) * table->philo_num);
	// null guard
	memset(table->states, THINKING, table->philo_num * sizeof(int));

	
	table->minimum_eat = -1;
	if (ac == 6)
		table->minimum_eat = atoi(av[5]);
	
	table->last_eat_times = (t_timestamp *)malloc(sizeof(t_timestamp) * table->philo_num);
	pthread_mutex_init(&(table->lock), NULL);
	gettimeofday(&table->start_time, NULL);
	i = -1;
	while (++i < table->philo_num)
		table->last_eat_times[i] = table->start_time;
	table->eof = 0;
}

void	*philosopher(void *arg)
{
	int				id;
	int				*state;
	t_dining_table	*table;
	
	id = ((t_philo *)arg)->id;
	state = ((t_philo *)arg)->state;
	table = ((t_philo *)arg)->table;
	while (1)
	{
		if (table->eof)
			break ;
		pickup(id, state, table);
		if (*state!= EATING)
			continue ;
		eating(id, table->time_info[TIME_2_EAT], table);
		sleeping(id, state, table->time_info[TIME_2_SLEEP], table);
		thinking(id, state, table->start_time);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	if (!(ac == 5 || ac == 6))
	{
		printf("arguments error\n");
		return (1);
	}

	t_dining_table	table;
	pthread_t		*tid;
	t_philo			*a_philo;
	int	i;
	
	init(ac, av, &table);
	tid = (pthread_t *)malloc(sizeof(pthread_t) * table.philo_num);
	i = -1;
	while (++i < table.philo_num)
	{
		a_philo = (t_philo *)malloc(sizeof(t_philo));
		a_philo->table = &table;	
		a_philo->id = i;
		a_philo->state = &(table.states[i]);
		pthread_create(&(tid[i]), NULL, philosopher, (void *)a_philo);
	}
	while (!check_die(&table)) 
		usleep(8);
	table.eof = 1;
	i = -1;
	while (++i < table.philo_num)
	{
		if (pthread_join(tid[i], NULL) == 0)
		{
			printf("dead!!!\n");
			break ;
		}
	}
	// do_free(&table, tid)
}