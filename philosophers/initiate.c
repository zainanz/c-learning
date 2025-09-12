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
	if ((get_current_time() - philo->last_eaten) > philo->data->die_time)
	{
		printf("%ld %i died\n", get_current_time() - philo->data->start_time, philo->id);
		return (1);
	}
	return (0);
}

int should_stop(t_data *data)
{
	int	i;
	int	full;
	int	ret;
	
	i = 0;
	ret = 0;
	full = 0;
	while(i < data->n_philos)
	{
		pthread_mutex_lock(&data->philos[i].eat_mutex);
		if (philo_dead(&data->philos[i]))
		{
			pthread_mutex_unlock(&data->philos[i].eat_mutex);
			ret = 1;
			break ;
		}
		full += philo_full(&data->philos[i]);
		pthread_mutex_unlock(&data->philos[i].eat_mutex);
		i++;
	}
	if (data->n_eats != -1 && full >= data->n_philos)
		ret = 1;
	return (ret);
}

void	monitor_philos(void *ptr)
{
	t_data	*data;

	data = (t_data *)ptr;
	while (1)
	{
		if (should_stop(data))
		{
			pthread_mutex_lock(&data->mutex_stop);
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
		safe_create_thread(&data->philos[i].thread, routine, (void *)&data->philos[i], data);
	safe_create_thread(&monitor, monitor_philos, (void *)data, data);
	pthread_join(monitor, NULL);
	i = -1;
	while (++i < data->n_philos)
		pthread_join(data->philos[i].thread, NULL);
}