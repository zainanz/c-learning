#include "philo.h"

int	display_status(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->mutex_stop);
	if (philo->data->stop)
	{
		pthread_mutex_unlock(&philo->data->mutex_stop);
		return (1);
	}
	printf("%ld\t%i\t%s", get_current_time() - philo->data->start_time,
		philo->id + 1, str);
	pthread_mutex_unlock(&philo->data->mutex_stop);
	return (0);
}

void	clean_up(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->mutex_stop);
	while (i < data->n_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].eat_mutex);
		i++;
	}
}

void	ft_usleep(size_t ms)
{
	size_t	start;

	start = get_current_time();
	while (get_current_time() - start < ms)
		usleep(500);
}
