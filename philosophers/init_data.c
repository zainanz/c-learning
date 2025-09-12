#include "philo.h"

static void	create_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philos)
	{
		safe_mutex_init(&data->forks[i], data);
		i++;
	}
}

void	init_data(char **argv, t_data *data, pthread_mutex_t *forks, t_philo *philos)
{
	data->n_philos = ft_atoi(argv[1]);
	data->start_time = get_current_time();
	safe_mutex_init(&data->mutex_stop, data);
	data->philos = philos;
	data->stop = 0;
	data->forks = forks;
	create_forks(data);
	data->die_time = ft_atoi(argv[2]);
	data->eat_time = ft_atoi(argv[3]);
	data->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
		data->n_eats= ft_atoi(argv[5]);
	else
		data->n_eats = -1;
}
