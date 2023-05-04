/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mutex_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 15:20:42 by heson             #+#    #+#             */
/*   Updated: 2023/05/04 14:21:02 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_end(t_info *info)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&info->lock);
	ret = info->is_end;
	pthread_mutex_unlock(&info->lock);
	return (ret);
}

void	set_end(t_info *info, int value)
{
	pthread_mutex_lock(&info->lock);
	info->is_end = value;
	pthread_mutex_unlock(&info->lock);
}

t_timestamp	get_last_eat_of(int i, t_table *table, t_info *info)
{
	t_timestamp	ret;

	pthread_mutex_lock(&info->lock);
	ret = table->last_eats[i];
	pthread_mutex_unlock(&info->lock);
	return (ret);
}

int	get_eat_cnt_of(int i, t_table *table, t_info *info)
{
	int	ret;

	pthread_mutex_lock(&info->lock);
	ret = table->eat_counts[i];
	pthread_mutex_unlock(&info->lock);
	return (ret);
}

void	print_state(int id, t_info *info, char *str)
{
	long long	ms;
	t_timestamp	cur;

	pthread_mutex_lock(&info->print_lock);
	if (!check_end(info))
	{
		gettimeofday(&cur, NULL);
		ms = get_timestamp(cur, info->start_time);
		printf("%lld %d %s\n", ms, id + 1, str);
	}
	pthread_mutex_unlock(&info->print_lock);
}
