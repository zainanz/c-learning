#ifndef PHILO_H
# define PHILO_H
# ifndef MAX_LIMIT
#  define MAX_LIMIT 200 
# endif

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	int				n_eats;
	size_t			last_eaten;
	t_data			*data;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	*r_fork;
	pthread_t		thread;
}	t_philo;

typedef struct s_data
{
	int				n_philos;
	int				n_eats;
	short			stop;
	int				die_time;
	size_t			start_time;
	int				sleep_time;
	int				eat_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_stop;
}	t_data;

// Str Utils
void			ft_putstr_fd(char *str, int fd);
int				ft_strlen(char *str);
int				get_valid_num(char *str);
size_t			get_current_time(void);
int				ft_isdigit(char c);

// Utils
int				display_status(t_philo *philo, char *str);
void			clean_up(t_data *data);
void			ft_usleep(size_t ms);

// Inits
void			init_data(char **argv, t_data *data,
					pthread_mutex_t *forks, t_philo *philos);
void			init_philos(t_data *data);
void			philo_routine(void *ptr);

// Begin Dinner
void			initiate(t_data *data);

// Safe Calls
void			safe_create_thread(pthread_t *addr,
					void *routine, void *ptr, t_data *data);
void			safe_mutex_init(pthread_mutex_t	*mutex, t_data *data);
#endif