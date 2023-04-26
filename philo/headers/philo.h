/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@Student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 14:57:08 by heson             #+#    #+#             */
/*   Updated: 2023/04/26 17:56:40 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h> //printf
#include <string.h> // memset
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

enum e_argu {
	PHILO_N = 0,
	TIME_2_DIE,
	TIME_2_EAT,
	TIME_2_SLEEP,
	EAT_MIN,
};

enum e_state {
	THINKING = 0,
	EATING,
	SLEEPING,
	DIED
};

typedef struct s_thread_info {
	int				id;
	int				*state;
	int				*philo_info;
	pthread_mutex_t	*lock;
	struct timeval	start_time;
}	t_thread_info;

void    check_die(int id, int *state, int time, struct timeval start);
void	pickup(pthread_mutex_t *lock, int id, int *state, int philo_n, struct timeval start);
void	eating(int id, int time, struct timeval start);
void	sleeping(int id, int *state, int time, struct timeval start);
void	thinking(int id, int *state, struct timeval start);


#endif