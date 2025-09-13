#include "philo.h"

static int	philo_full(t_philo *philo)
{
	if (philo->data->n_eats == -1)
		return (0);
	if (philo->n_eats >= philo->data->n_eats)
		return (1);
	return (0);
}

int	philo_dead(t_philo *philo)
{
	if ((get_current_time() - philo->last_eaten) > (size_t)philo->data->die_time)
	{
		pthread_mutex_lock(&philo->data->mutex_stop);
		printf("\33[31m%ld\t%i\t died\33[0m\n", get_current_time() - philo->data->start_time, philo->id);
		return (1);
	}
	return (0);
}

int should_stop(t_data *data)
{
	int	i;
	int	full;
	
	i = 0;
	full = 0;
	while(i < data->n_philos)
	{
		pthread_mutex_lock(&data->philos[i].eat_mutex);
		if (philo_dead(&data->philos[i]))
		{
			pthread_mutex_unlock(&data->philos[i].eat_mutex);
			return (1);
		}
		full += philo_full(&data->philos[i]);
		pthread_mutex_unlock(&data->philos[i].eat_mutex);
		i++;
	}
	if (data->n_eats != -1 && full >= data->n_philos)
	{
		pthread_mutex_lock(&data->mutex_stop);
		return (1);
	}
	return (0);
}

void	monitor_philos(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	while (1)
	{
		if (should_stop(data))
		{
			data->stop = 1;
			pthread_mutex_unlock(&data->mutex_stop);
			break ;
		}
	}
} 

void	initiate(t_data *data)
{
	int			i;
	pthread_t	monitor;

	i = -1;
	while (++i < data->n_philos)
		safe_create_thread(&data->philos[i].thread, philo_routine, (void *)&data->philos[i], data);
	safe_create_thread(&monitor, monitor_philos, (void *)data, data);
	pthread_join(monitor, NULL);
	i = -1;
	while (++i < data->n_philos)
		pthread_join(data->philos[i].thread, NULL);
}