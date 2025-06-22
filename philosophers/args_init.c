/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 17:28:46 by zali              #+#    #+#             */
/*   Updated: 2025/06/21 19:29:46 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	set_args(philos_arg *args, int str_size, char **str)
{
	args->total = atoi(str[1]);
	args->die_time = atoi(str[2]);
	args->eat_time = atoi(str[3]);
	args->sleep_time = atoi(str[4]);
	args->total_eat = 0;
	if (str_size == 6)
		args->total_eat = atoi(str[5]);
	args->begin_time = get_current_time();
	pthread_mutex_init(&args->stop_mutex, NULL);
	pthread_mutex_lock(&args->stop_mutex);
	args->stop = 0;
	pthread_mutex_unlock(&args->stop_mutex);
	args->forks = NULL;
	if (args->total)
		args->philos = malloc(sizeof(philo) * args->total);
	else
	{
		ft_putstr_fd(STDERR_FILENO, "Invalid Arguments.");
		exit(EXIT_FAILURE);
	}
}

void	create_forks(philos_arg *args)
{
	int	i;

	i = 0;
	args->forks = malloc(sizeof(pthread_mutex_t) * args->total);
	while (i < args->total)
	{
		pthread_mutex_init(args->forks + i, NULL);
		i++;
	}
}
