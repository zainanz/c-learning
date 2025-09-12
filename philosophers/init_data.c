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

void	validate_argv(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				ft_putstr_fd("argument can only be a \033[33mpositive number\033[0m\n", 2);
				ft_putstr_fd("\033[33m[USAGE]\033[0m ./philo 'number_of_philosophers' 'time_to_die'"
					" 'time_to_eat' 'time_to_sleep'"
					" 'number_of_times_each_philosopher_must_eat (optional)'\n", 2);
				exit(EXIT_FAILURE);
			}
			j++;
		}	
		i++;
	}
}

void	init_data(char **argv, t_data *data, pthread_mutex_t *forks, t_philo *philos)
{
	validate_argv(argv);
	data->n_philos = ft_atoi(argv[1]);
	if (data->n_philos == 0)
		exit(EXIT_SUCCESS);
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
	{
		data->n_eats= ft_atoi(argv[5]);
		if (data->n_eats == 0)
			exit(EXIT_SUCCESS);
	}
	else
		data->n_eats = -1;
}
