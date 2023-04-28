/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 02:46:53 by heson             #+#    #+#             */
/*   Updated: 2023/04/28 02:49:26 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/philo.h"

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
}