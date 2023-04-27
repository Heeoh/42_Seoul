/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@Student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:56:26 by heson             #+#    #+#             */
/*   Updated: 2023/04/27 21:35:24 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"
#include <stdlib.h> //atoi 

void	init_table(int ac, char *av[], t_dining_table *table)
{
	// parsing error
	table->philo_num = atoi(av[1]);
	table->time_2_die = atoi(av[2]);
	table->time_2_eat = atoi(av[3]);
	table->time_2_sleep = atoi(av[4]);
	table->minimum_eat = -1;
	if (ac == 6)
		table->minimum_eat = atoi(av[5]);
	pthread_mutex_init(&(table->lock), NULL);
	gettimeofday(&table->start_time, NULL);
	table->eof = 0;
}

void	init_philos(t_philo **philos, int **states, t_timestamp **last_eats, t_dining_table *table)
{
	int	i;
	int	left;
	int	right;
	
	*states = (int *)malloc(sizeof(int) * table->philo_num);
	// null guard
	memset(*states, THINKING, table->philo_num * sizeof(int));
	*last_eats = (t_timestamp *)malloc(sizeof(t_timestamp) * table->philo_num);
	*philos = (t_philo *)malloc(sizeof(t_philo) * table->philo_num);
	i = table->philo_num;
	while (--i >= 0)
	{
		(*last_eats)[i] = table->start_time;
		(*philos)[i].id = i;
		(*philos)[i].state = (*states) + i;
		left = (i + table->philo_num - 1) % table->philo_num;
		right = (i + 1) % table->philo_num;
		(*philos)[i].sides[LEFT] = (*states) + left;
		(*philos)[i].sides[RIGHT] = (*states) + right;
		(*philos)[i].last_eat = (*last_eats) + i;
		(*philos)[i].table = table;
	}
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
		pickup(id, state, ((t_philo *)arg)->sides, table);
		if (*state!= EATING)
			continue ;
		if (!table->eof)
			eating(id, table->time_2_eat, ((t_philo *)arg)->last_eat, table);
		if (!table->eof)
			sleeping(id, state, table->time_2_sleep, table);
		if (!table->eof)
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
	t_monitoring	monitoring;
	pthread_t		*tid;
	t_philo			*philos;
	int	i;
	
	init_table(ac, av, &table);
	init_philos(&philos, &(monitoring.states), &(monitoring.last_eats), &table);
	tid = (pthread_t *)malloc(sizeof(pthread_t) * table.philo_num);

	i = -1;
	while (++i < table.philo_num)
		pthread_create(&(tid[i]), NULL, philosopher, (void *)(philos + i));
	while (!check_die(&table, monitoring));
	table.eof = 1;
	printf("dead start\n");
	i = -1;
	while (++i < table.philo_num)
	{
		if (pthread_join(tid[i], NULL) == 0)
			printf("%d dead!!!\n", i);
	}
	// do_free(&table, tid)
}