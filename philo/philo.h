/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 03:14:16 by heson             #+#    #+#             */
/*   Updated: 2023/04/29 02:17:28 by heson            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h> //printf
# include <string.h> // memset
# include <stdlib.h> // malloc, free
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

# define ERROR -1
# define FAIL 0
# define SUCCESS 1

typedef struct timeval t_timestamp;

typedef struct	s_info {
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				minimum_eat;
	t_timestamp		start_time;
	char			is_end;
	pthread_mutex_t	lock;
}	t_info;

typedef struct	s_table {
	pthread_mutex_t	*forks;
	int				*eat_counts;
	t_timestamp		*last_eats;
}	t_table;

typedef struct	s_philo {
	int				id;
	t_timestamp 	*last_eat;
	int				*eat_cnt;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_info			*info;
}	t_philo;

// init
int		init_info( t_info *info, int ac, char *av[]);
int		init_table(t_table *table, t_info info);
int		init_philos(t_philo **philos, t_info *info, t_table *table, pthread_t **tid);

// utils
int		get_timestamp(t_timestamp prev);
void	custom_usleep(int wait_time, t_timestamp prev);
void	do_free(t_table *table, t_philo *philos, pthread_t *tid);
int		check_end(t_philo *p);
int		ft_atoi(const char *str);

// acting
int		pickup(t_philo *p);
void	eating(t_philo *p);
void	putdown(t_philo	*p);
void	sleeping(t_philo *p);
void	thinking(t_philo *p);

#endif