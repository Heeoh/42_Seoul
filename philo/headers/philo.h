/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@Student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:08 by heson             #+#    #+#             */
/*   Updated: 2023/04/27 18:52:12 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h> //printf
#include <string.h> // memset
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct timeval t_timestamp;

enum e_time_argu {
	TIME_2_DIE = 0,
	TIME_2_EAT,
	TIME_2_SLEEP,
};

enum e_state {
	THINKING = 0,
	EATING,
	SLEEPING,
	DIED
};

typedef struct s_dining_table {
	int				philo_num;
	int				time_2_die;
	int				time_2_eat;
	int				time_2_sleep;
	int				minimum_eat;
	
	int				*states;
	
	struct timeval	start_time;
	t_timestamp		*last_eat_times;
	pthread_mutex_t	lock;
	int				eof;
}	t_dining_table;

typedef struct s_philo {
	int				id;
	int				*state;
	t_dining_table	*table;
}	t_philo;

int		check_die(t_dining_table *table);
void	pickup(int id, int *state, t_dining_table *table);
void	eating(int id, int eating_time,  t_dining_table *table);
void	sleeping(int id, int *state, int sleeping_time, t_dining_table *table);
void	thinking(int id, int *state, t_timestamp start);

#endif