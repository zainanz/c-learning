#include "philo.h"

void	safe_mutex_init(pthread_mutex_t	*mutex, t_data *data)
{
	if (pthread_mutex_init(mutex, NULL))
	{
		clean_up(data);
		perror("mutex init fail");
		exit(EXIT_FAILURE);
	}
}

void	safe_create_thread(pthread_t *addr, void *routine, void *ptr, t_data *data)
{
	if (pthread_create(addr, NULL, routine, ptr) != 0)
	{
		clean_up(data);
		perror("thread create fail\n");
		exit(EXIT_FAILURE);
	}
}
