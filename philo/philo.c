/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 03:14:00 by heson             #+#    #+#             */
/*   Updated: 2023/05/01 16:26:10 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitoring(t_table *table, t_info *info)
{
	int			i;
	int			hungry_time;
	int			full_philos;
	t_timestamp	cur;

	i = -1;
	full_philos = 0;
	while (++i < info->number_of_philos)
	{
		if (get_eat_cnt_of(i, table, info) == 0 && full_philos++)
			continue ;
		gettimeofday(&cur, NULL);
		hungry_time = get_timestamp(cur, get_last_eat_of(i, table, info));
		if (hungry_time >= info->time_to_die)
		{
			print_state(i, info, "died");
			set_end(info, 1);
			break ;
		}
	}
	if (full_philos == info->number_of_philos)
	{
		printf("All of philosophers are full\n");
		set_end(info, 1);
	}
}

void	*philosopher(void *arg)
{
	t_philo	*a_philo;

	a_philo = (t_philo *)arg;
	if (a_philo->id % 2 == 0)
		custom_usleep(a_philo->info->time_to_eat, *a_philo->last_eat);
	while (!check_end(a_philo->info))
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

void	enjoy_meal(t_info *info, t_table *table, t_philo *philos,
			pthread_t *tid)
{
	int	i;

	i = 0;
	gettimeofday(&info->start_time, NULL);
	while (i < info->number_of_philos)
	{
		*(philos[i].last_eat) = info->start_time;
		pthread_create(&(tid[i]), NULL, philosopher, (void *)(philos + i));
		i++;
	}
	while (!check_end(info))
		monitoring(table, info);
	i = -1;
	while (++i < info->number_of_philos)
		pthread_join(tid[i], NULL);
	i = -1;
	while (++i < info->number_of_philos)
		pthread_mutex_destroy(&table->forks[i]);
	pthread_mutex_destroy(&info->lock);
	pthread_mutex_destroy(&info->print_lock);
}

int	main(int ac, char *av[])
{
	t_info		info;
	t_table		table;
	t_philo		*philos;
	pthread_t	*tid;

	table.forks = NULL;
	table.eat_counts = NULL;
	table.last_eats = NULL;
	philos = NULL;
	tid = NULL;
	if (init_info(&info, ac, av) == ERROR || init_table(&table, info) == ERROR
		|| init_philos(&philos, &info, &table, &tid) == ERROR)
	{
		do_free(&table, philos, tid);
		return (1);
	}
	enjoy_meal(&info, &table, philos, tid);
	do_free(&table, philos, tid);
	return (0);
}
