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

static void	invalid_n_philos(char *str)
{
	ft_putstr_fd("\033[31m[ERROR]\033[0m 200 is the max"
		" num of philos test range.\n", 2);
	ft_putstr_fd("\033[33m[INFO]\033[0m \"make re limit=", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\" to test your value.\n", 2);
	exit(EXIT_FAILURE);
}

void	init_data(char **argv, t_data *data
			, pthread_mutex_t *forks, t_philo *philos)
{
	data->n_philos = get_valid_num(argv[1]);
	if (data->n_philos > MAX_LIMIT)
		invalid_n_philos(argv[1]);
	if (data->n_philos == 0)
		exit(EXIT_SUCCESS);
	data->start_time = get_current_time();
	safe_mutex_init(&data->mutex_stop, data);
	data->philos = philos;
	data->stop = 0;
	data->forks = forks;
	create_forks(data);
	data->die_time = get_valid_num(argv[2]);
	data->eat_time = get_valid_num(argv[3]);
	data->sleep_time = get_valid_num(argv[4]);
	if (argv[5])
	{
		data->n_eats = get_valid_num(argv[5]);
		if (data->n_eats == 0)
			exit(EXIT_SUCCESS);
	}
	else
		data->n_eats = -1;
}
