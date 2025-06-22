/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 17:17:28 by zali              #+#    #+#             */
/*   Updated: 2025/06/21 19:26:58 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char *argv[])
{
	philos_arg	p_args;

	if (argc != 5 && argc != 6)
	{
		ft_putstr_fd(STDERR_FILENO,
			"./philo [num of philos] [time to die] [time to eat] [time to sleep] [total eat]\n");
		exit(EXIT_FAILURE);
	}
	set_args(&p_args, argc, argv);
	create_forks(&p_args);
	create_philos(&p_args);
	start_observer(&p_args);
	wait_philos(&p_args);
}
