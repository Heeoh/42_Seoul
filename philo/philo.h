/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heson <heson@Student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 03:14:16 by heson             #+#    #+#             */
/*   Updated: 2023/05/04 15:43:11 by heson            ###   ########.fr       */
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
# define SOMEONE_DEAD 1
# define EVERYONE_FULL 2

typedef struct timeval	t_timestamp;

typedef struct s_info {
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				minimum_eat;
	t_timestamp		start_time;
	char			is_end;
	pthread_mutex_t	lock;
	pthread_mutex_t	print_lock;
}	t_info;

typedef struct s_table {
	pthread_mutex_t	*forks;
	int				*eat_counts;
	t_timestamp		*last_eats;
}	t_table;

typedef struct s_philo {
	int				id;
	t_timestamp		*last_eat;
	int				*eat_cnt;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_info			*info;
}	t_philo;

// init
int			init_info( t_info *info, int ac, char *av[]);
int			init_table(t_table *table, t_info info);
int			init_philos(t_philo **philos, t_info *info, t_table *table,
				pthread_t **tid);

// utils
long long	get_timestamp(t_timestamp cur, t_timestamp prev);
void		custom_usleep(long long wait_time, t_timestamp prev);
void		do_free(t_table *table, t_philo *philos, pthread_t *tid);
int			ft_atoi(const char *str);

// mutex_utils
int			check_end(t_info *info);
void		set_end(t_info *info, int value);
t_timestamp	get_last_eat_of(int i, t_table *table, t_info *info);
int			get_eat_cnt_of(int i, t_table *table, t_info *info);
void		print_state(int id, t_info *info, char *str);

// acting
int			pickup(t_philo *p);
void		eating(t_philo *p);
void		putdown(t_philo	*p);
void		sleeping(t_philo *p);
void		thinking(t_philo *p);

#endif