/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@Student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 01:30:19 by heson             #+#    #+#             */
/*   Updated: 2023/05/01 17:18:41 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_right_argus(int ac, t_info *info)
{
	if (info->number_of_philos <= 0 || info->time_to_die <= 0
		|| info->time_to_eat <= 0 || info->time_to_sleep <= 0
		|| (ac == 6 && info->minimum_eat <= 0))
	{
		printf("Error: Invalid arguments");
		return (-1);
	}
	return (0);
}

int	init_info( t_info *info, int ac, char *av[])
{
	if (!(ac == 5 || ac == 6))
	{
		printf("Error: 5 or 6 arguments are required\n");
		return (-1);
	}
	info->number_of_philos = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->minimum_eat = -1;
	if (ac == 6)
		info->minimum_eat = ft_atoi(av[5]);
	info->is_end = 0;
	pthread_mutex_init(&info->lock, NULL);
	pthread_mutex_init(&info->print_lock, NULL);
	return (is_right_argus(ac, info));
}

int	init_table(t_table *table, t_info info)
{
	int	i;

	table->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* info.number_of_philos);
	table->eat_counts = (int *)malloc(sizeof(int) * info.number_of_philos);
	table->last_eats = (t_timestamp *)malloc(sizeof(t_timestamp)
			* info.number_of_philos);
	if (!table->forks || !table->eat_counts || !table->last_eats)
	{
		printf("Error malloc failed\n");
		return (-1);
	}
	i = info.number_of_philos;
	while (--i >= 0)
	{
		pthread_mutex_init(table->forks + i, NULL);
		table->eat_counts[i] = info.minimum_eat;
	}
	return (0);
}

int	init_philos(t_philo **philos, t_info *info, t_table *table, pthread_t **tid)
{
	int	i;

	*philos = (t_philo *)malloc(sizeof(t_philo) * info->number_of_philos);
	*tid = (pthread_t *)malloc(sizeof(pthread_t) * info->number_of_philos);
	if (!*philos || !*tid)
	{
		printf("Error: malloc failed\n");
		return (-1);
	}
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
