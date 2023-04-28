/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:08 by heson             #+#    #+#             */
/*   Updated: 2023/04/28 03:05:34 by heson            ###   ########.fr       */
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

#define OFF 0
#define ON 1

// enum e_state {
// 	THINKING = 0,
// 	EATING,
// 	SLEEPING,
// };

// typedef struct	s_info {
// 	int				philo_num;
// 	int				time_2_die;
// 	int				time_2_eat;
// 	int				time_2_sleep;
// 	int				minimum_eat; // not yet
// 	t_timestamp		start_time;
// }	t_info;

typedef struct	s_dining_table {
	int				philo_num;
	int				time_2_die;
	int				time_2_eat;
	int				time_2_sleep;
	int				minimum_eat; // not yet
	t_timestamp		start_time;
	pthread_mutex_t	lock;
	char			*forks;
	char			eof;
}	t_dining_table;

typedef struct s_philo {
	int				id;
	// int				state;
	t_timestamp		*last_eat;
	int				*eat_cnt;
	// char			*l_fork;
	// char			*r_fork;
	t_dining_table	*table;
	// t_info			info;
}	t_philo;

typedef struct s_monitoring {
	t_timestamp	*last_eats;
	int			*eat_cnt;
}	t_monitoring;

int		check_die(t_dining_table *table, t_monitoring moni);
void	pickup(int id, int *state, int **sides, t_dining_table *table);
void	eating(int id, int eating_time, t_timestamp *last_eat, t_dining_table *table);
void	sleeping(int id, int *state, int sleeping_time, t_dining_table *table);
void	thinking(int id, int *state, t_timestamp start);

#endif