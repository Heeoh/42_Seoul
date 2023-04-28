/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:56:26 by heson             #+#    #+#             */
/*   Updated: 2023/04/28 03:11:54 by heson            ###   ########.fr       */
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
	table->forks = (char *)malloc(sizeof(char) * table->philo_num);
	memset(table->forks, 0, sizeof(char) * table->philo_num);
	gettimeofday(&table->start_time, NULL);
	table->eof = 0;
}

void	init_philos(t_philo **philos, t_timestamp **last_eats, int **eat_cnt, t_dining_table *table)
{
	int	i;
	int	left;
	int	right;
	
	*eat_cnt = (int *)malloc(sizeof(int) * table->philo_num);
	// null guard
	memset(*eat_cnt, 0, table->philo_num * sizeof(int));
	*last_eats = (t_timestamp *)malloc(sizeof(t_timestamp) * table->philo_num);
	*philos = (t_philo *)malloc(sizeof(t_philo) * table->philo_num);
	i = table->philo_num;
	while (--i >= 0)
	{
		(*last_eats)[i] = table->start_time;
		(*philos)[i].id = i;
		(*philos)[i].last_eat = (*last_eats) + i;
		(*philos)[i].eat_cnt = (*eat_cnt) + i;
		(*philos)[i].table = table;
	}
}

void	*philosopher(void *arg)
{
	t_philo	*a_philo;
	
	a_philo = (t_philo *)arg;
	while (1)
	{
		if (a_philo->table->eof)
			break ;
		pickup(a_philo->id, state, ((t_philo *)arg)->sides, table);
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
	init_philos(&philos, )
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