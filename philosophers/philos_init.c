/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:27:14 by zali              #+#    #+#             */
/*   Updated: 2025/06/21 22:25:56 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_stop(philo *philo)
{
	int	return_status;

	return_status = 0;
	pthread_mutex_lock(&philo->data->stop_mutex);
	pthread_mutex_lock(&philo->dead_mutex);
	if (philo->data->stop)
		return_status = 1;
	if (philo->dead)
	{
		philo->data->stop = 1;
		return_status = 1;
	}
	pthread_mutex_unlock(&philo->dead_mutex);
	pthread_mutex_unlock(&philo->data->stop_mutex);
	return (return_status);
}

static void	*routines(void *ptr)
{
	philo	*phil;

	phil = (philo *)ptr;
	if (phil->id % 2 == 0)
	{
		think(phil);
		ft_sleep(1);
	}
	while (!check_stop(ptr))
	{
		if (!eat(phil))
			continue ;
		if (!psleep(phil))
			continue ;
		if (!think(phil))
			continue ;
	}
	return (NULL);
}

void	create_philos(philos_arg *args)
{
	int	i;

	i = 0;
	while (i < args->total)
	{
		if (pthread_create(&args->philos[i].thread, NULL, &routines,
				&args->philos[i]) != 0)
		{
			ft_putstr_fd(STDERR_FILENO, "Failed to create thread.\n");
			exit(EXIT_FAILURE);
		};
		args->philos[i].id = i;
		args->philos[i].last_meal = get_current_time();
		args->philos[i].eaten = 0;
		args->philos[i].eating = 0;
		args->philos[i].dead = 0;
		args->philos[i].data = args;
		args->philos[i].fork_a = args->forks + i;
		pthread_mutex_init(&args->philos[i].meal_mutex, NULL);
		pthread_mutex_init(&args->philos[i].dead_mutex, NULL);
		if (i == 0)
			args->philos[i].fork_b = &args->forks[args->total - 1];
		else
			args->philos[i].fork_b = &args->forks[i - 1];
		i++;
	}
}

void	wait_philos(philos_arg *args)
{
	int	i;

	i = 0;
	while (i < args->total)
	{
		if (pthread_join(args->philos[i].thread, NULL) != 0)
		{
			ft_putstr_fd(STDERR_FILENO, "Thread wait error.\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}
