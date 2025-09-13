#include "philo.h"

void eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	if (display_status(philo, " has taken a fork\n") || philo->data->n_philos == 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(philo->r_fork);
	if (display_status(philo, " has taken a fork\n")
		|| display_status(philo, " is eating\n"))
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(&philo->eat_mutex);
	philo->n_eats++;
	philo->last_eaten = get_current_time();
	pthread_mutex_unlock(&philo->eat_mutex);
	ft_usleep(philo->data->eat_time);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	philo_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
	{
		display_status(philo, " is thinking\n");
		ft_usleep(1);
	}
	while (1)
	{
		eat(philo);
		if (philo->data->n_philos == 1 || display_status(philo, " is sleeping\n"))
			break ;
		ft_usleep(philo->data->sleep_time);
		if (philo->data->n_philos == 1 || display_status(philo, " is thinking\n"))
			break ;
	}
}

void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		data->philos[i].data = data;
		data->philos[i].n_eats = 0;
		data->philos[i].id = i;
		data->philos[i].last_eaten = get_current_time();
		data->philos[i].l_fork = &data->forks[i];
		if (i == 0)
			data->philos[i].r_fork = &data->forks[data->n_philos - 1];
		else
			data->philos[i].r_fork = &data->forks[i - 1];
		safe_mutex_init(&data->philos[i].eat_mutex, data);
		i++;
	}
}
