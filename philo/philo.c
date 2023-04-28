/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@Student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 03:14:00 by heson             #+#    #+#             */
/*   Updated: 2023/04/28 21:56:16 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h> // atoi

// 정수범위...? 
int	is_right_argus(t_info *info)
{
	if (info->number_of_philos <= 0 || info->time_to_die <= 0
		|| info->time_to_eat <= 0 || info->time_to_sleep <= 0)
		return (-1);
	return (0);
}

int	init_info( t_info *info, int ac, char *av[])
{
	info->number_of_philos = atoi(av[1]);
	info->time_to_die = atoi(av[2]);
	info->time_to_eat = atoi(av[3]);
	info->time_to_sleep = atoi(av[4]);
	info->minimum_eat = -1;
	if (ac == 6)
		info->minimum_eat = atoi(av[5]);
	gettimeofday(&(info->start_time), NULL);
	info->is_end = 0;
	pthread_mutex_init(&info->lock, NULL);
	return (is_right_argus(info));
}

int	init_table(t_table *table, t_info info)
{
	int	i;

	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info.number_of_philos);
	table->eat_counts = (int *)malloc(sizeof(int) * info.number_of_philos);
	table->last_eats = (t_timestamp *)malloc(sizeof(t_timestamp) * info.number_of_philos);
	if (!table->forks || !table->eat_counts || !table->last_eats)
		return (-1);
	i = info.number_of_philos;
	while (--i >= 0)
	{
		pthread_mutex_init(table->forks + i, NULL);
		table->eat_counts[i] = info.minimum_eat;
		table->last_eats[i] = info.start_time;
	}
	return (0);
}

int	init_philos(t_philo **philos, t_info *info, t_table *table, pthread_t **tid)
{
	int	i;
	*philos = (t_philo *)malloc(sizeof(t_philo) * info->number_of_philos);
	*tid = (pthread_t *)malloc(sizeof(pthread_t) * info->number_of_philos);
	if (!*philos || !*tid)
		return (-1);
	i = info->number_of_philos;
	while (--i >= 0)
	{
		(*philos)[i].id = i;
		(*philos)[i].last_eat = table->last_eats + i;
		(*philos)[i].eat_cnt = table->eat_counts + i;
		(*philos)[i].l_fork = table->forks + i;
		(*philos)[i].r_fork = table->forks + ((i + 1) % info->number_of_philos);
		(*philos)[i].info = info;
	}
	return (0);
}

void	monitoring(t_table *table, t_info *info)
{
	int i;
	int	hungry_time;
	int	full_philos;


	i = -1;
	full_philos = 0;
	pthread_mutex_lock(&info->lock);
	while (++i < info->number_of_philos)
	{
		if (table->eat_counts[i] == 0 && full_philos++)
			continue ;
		hungry_time = get_timestamp(table->last_eats[i]);
		if (hungry_time >= info->time_to_die)
		{
			printf("%d %d died\n", get_timestamp(info->start_time), i + 1);
			info->is_end = 1;
			pthread_mutex_unlock(&info->lock);
			return ;
		}
	}
	if (full_philos == info->number_of_philos)
	{
		printf("+-----------------------------------+\n");
		printf("|    All of philosophers are full   |\n");
		printf("+-----------------------------------+\n");
		info->is_end = 1;
	}
	pthread_mutex_unlock(&info->lock);
}

void	*philosopher(void *arg)
{
	t_philo	*a_philo;

	a_philo = (t_philo *)arg;
	while (!a_philo->info->is_end)
	{
		if (!pickup(a_philo))
			continue ;
		eating(a_philo);
		putdown(a_philo);
		sleeping(a_philo);
		thinking(a_philo);
	}
	return (0);
}

int	main(int ac, char *av[])
{
	t_info		info;
	t_table		table;
	t_philo		*philos;
	pthread_t	*tid;
	int			i;

	if (!(ac == 5 || ac == 6))
	{
		printf("Error: 5 or 6 arguments are required\n");
		return (1);
	}
	if (init_info(&info, ac, av) < 0)
		return (1);
	if (init_table(&table, info) < 0)
		return (1);	
	if (init_philos(&philos, &info, &table, &tid) < 0)
		return (1);
	i = 0;
	while (i < info.number_of_philos)
	{
		pthread_create(&(tid[i]), NULL, philosopher, (void *)(philos + i));
		i += 2;
	}
	i = 1;
	while (i < info.number_of_philos)
	{
		pthread_create(&(tid[i]), NULL, philosopher, (void *)(philos + i));
		i += 2;
	}
	while (!info.is_end)
		monitoring(&table, &info);
	i = -1;
	while (++i < info.number_of_philos)
		pthread_join(tid[i], NULL);
	// do_free(&table, philos, tid);
}