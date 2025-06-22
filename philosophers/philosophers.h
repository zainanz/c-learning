/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:50:46 by zali              #+#    #+#             */
/*   Updated: 2025/06/21 19:07:46 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct t_philos_arg philos_arg;

typedef struct t_philos {
	pthread_t		thread;
	int				id;
	int				eaten;
	int				dead;
	int				eating;
	size_t			last_meal;
	pthread_mutex_t	*fork_a;
	pthread_mutex_t *fork_b;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	meal_mutex;
	philos_arg		*data;
}	philo;

typedef struct t_philos_arg
{
	size_t			sleep_time;
	size_t			die_time;
	size_t			eat_time;
	size_t			begin_time;
	size_t			total_eat;
	int				total;
	int				stop;
	philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	stop_mutex;
}	philos_arg;

// Utils
size_t	get_current_time(void);
int		ft_sleep(size_t milliseconds);
void	ft_putstr_fd(int fd, char *str);

// Philosphers Action
int		eat(philo *philo);
void	psleep(philo *philo);
void	think(philo *philo);

// Args Struct Init
void	set_args(philos_arg *args, int str_size, char **str);
void	create_forks(philos_arg	*args);

// Philosophers Init
void	create_philos(philos_arg *args);
void	wait_philos(philos_arg *args);

// Observer
void	start_observer(philos_arg *args);

#endif
