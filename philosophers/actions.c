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

void	think(philo *philo)
{
	timed_message("%lu %i is thinking\n", philo);
}

void	psleep(philo *philo)
{
	timed_message("%lu %i is sleeping\n", philo);
	ft_sleep(philo->data->sleep_time);
}

int still_alive(philo *philo)
{
	int	return_status;

	return_status = 1;
	pthread_mutex_lock(&philo->dead_mutex);
	pthread_mutex_lock(&philo->meal_mutex);
	if (get_current_time() - philo->last_meal >= philo->data->die_time)
	{
		philo->dead = 1;
		return_status = 0;
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(&philo->dead_mutex);
	return (return_status);
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
	if (!still_alive(philo))
		return (0);
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
