/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 13:14:50 by zali              #+#    #+#             */
/*   Updated: 2025/06/21 19:32:04 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	timed_message(char *str, philo *philo)
{
	printf(str, get_current_time() - philo->data->begin_time, philo->id);
}

/*int still_alive(philo *philo)
{
	int	return_status;

	return_status = 1;
	pthread_mutex_lock(&philo->data->stop_mutex);
	pthread_mutex_lock(&philo->dead_mutex);
	pthread_mutex_lock(&philo->meal_mutex);
	if (get_current_time() - philo->last_meal >= philo->data->die_time)
	{
		philo->dead = 1;
		return_status = 0;
	}
	if (philo->data->stop == 1)
		return_status = 0;
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(&philo->dead_mutex);
	pthread_mutex_unlock(&philo->data->stop_mutex);
	return (return_status);
}
*/
int	stop_signal(philos_arg *args)
{
	int	return_status;

	return_status = 0;
	pthread_mutex_lock(&args->stop_mutex);
	if (args->stop)
		return_status = 1;
	pthread_mutex_unlock(&args->stop_mutex);
	return (return_status);
}

int	think(philo *philo)
{
	if (stop_signal(philo->data))
		return (0);
	timed_message("%lu %i is thinking\n", philo);
	return (1);
}

int	psleep(philo *philo)
{
	if (stop_signal(philo->data))
		return (0);
	timed_message("%lu %i is sleeping\n", philo);
	ft_sleep(philo->data->sleep_time);
	return (1);
}

int	eat(philo *philo)
{
	if (philo->data->total == 1)
	{
		ft_sleep(philo->data->die_time);
		return (0);
	}
	pthread_mutex_lock(philo->fork_a);
	pthread_mutex_lock(philo->fork_b);
	if (stop_signal(philo->data))
	{
		pthread_mutex_unlock(philo->fork_a);
		pthread_mutex_unlock(philo->fork_b);
		return (0);
	}
	timed_message("%lu %lu has taken a fork\n", philo);
	timed_message("%lu %i has taken a fork\n", philo);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->eating = 1;
	timed_message("%lu %i is eating\n", philo);
	ft_sleep(philo->data->eat_time);
	philo->eaten++;
	philo->eating = 0;
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(philo->fork_a);
	pthread_mutex_unlock(philo->fork_b);
	return (1);
}
