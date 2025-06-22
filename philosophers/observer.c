/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:26:19 by zali              #+#    #+#             */
/*   Updated: 2025/06/21 22:05:09 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check_if_all_full(philos_arg *args)
{
	int	i;
	int	total_eaten;

	i = 0;
	total_eaten = 0;
	while (i < args->total && args->total_eat)
	{
		pthread_mutex_lock(&args->philos[i].meal_mutex);
		if (args->philos[i].eaten >= args->total_eat)
			total_eaten++;
		pthread_mutex_unlock(&args->philos[i].meal_mutex);
		i++;
	}
	if (total_eaten >= args->total)
	{
		pthread_mutex_lock(&args->stop_mutex);
		args->stop = 1;
		pthread_mutex_unlock(&args->stop_mutex);
		return (1);
	}
	return (0);
}

int	check_and_update_dead(philos_arg *args)
{
	int	i;
	int	return_status;

	i = 0;
	return_status = 0;
	while (i < args->total && !return_status)
	{
		pthread_mutex_lock(&args->stop_mutex);
		pthread_mutex_lock(&args->philos[i].dead_mutex);
		pthread_mutex_lock(&args->philos[i].meal_mutex);
		if ((get_current_time() - args->philos[i].last_meal) >= args->die_time)
		{
			args->philos[i].dead = 1;
			args->stop = 1;
			return_status = 1;
		}
		pthread_mutex_unlock(&args->philos[i].dead_mutex);
		pthread_mutex_unlock(&args->stop_mutex);
		pthread_mutex_unlock(&args->philos[i].meal_mutex);
		i++;
	}
	return (return_status);
}

void	*monitoring(void *ptr)
{
	philos_arg	*args;
	int			i;

	args = (philos_arg *)ptr;
	while (1)
	{
		i = 0;
		while (i < args->total)
		{
			if (check_if_all_full(args) || check_and_update_dead(args))
			{
				ft_putstr_fd(1, "someone died.\n");
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}

void	start_observer(philos_arg *args)
{
	pthread_t	observer;

	if (pthread_create(&observer, NULL, &monitoring, args) != 0)
	{
		ft_putstr_fd(STDERR_FILENO, "Observer thread error.\n");
		exit(EXIT_FAILURE);
	}
	if (pthread_join(observer, NULL) != 0)
	{
		ft_putstr_fd(STDERR_FILENO, "Observer thread join failed.\n");
		exit(EXIT_FAILURE);
	}
}
