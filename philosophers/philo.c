#include "philo.h"

int	main(int argc, char *argv[])
{
	pthread_mutex_t	forks[MAX_LIMIT];
	t_philo			philos[MAX_LIMIT];
	t_data			data;

	if (argc != 5 && argc != 6)
	{
		ft_putstr_fd("invalid params.\n", 2);
		ft_putstr_fd("./philo 'number_of_philosophers' 'time_to_die'"
					" 'time_to_eat' 'time_to_sleep'"
					" 'number_of_times_each_philosopher_must_eat (optional)'\n",
					 2);
		return (1);
	}
	init_data(argv, &data, forks, philos);
	init_philos(&data);
	initiate(&data);
	clean_up(&data);
	return (0);
}