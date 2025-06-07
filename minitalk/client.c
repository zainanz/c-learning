/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 21:21:48 by zali              #+#    #+#             */
/*   Updated: 2025/06/05 22:12:31 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdlib.h>

volatile sig_atomic_t	g_wait_ack = 0;

void	send_bits(int sender_pid, char c)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (c & (0b10000000 >> bits))
			kill(sender_pid, SIGUSR1);
		else
			kill(sender_pid, SIGUSR2);
		bits++;
		while (g_wait_ack)
			usleep(10);
		g_wait_ack = 1;
	}
}

void	handler(int signo, siginfo_t *info, void *more)
{
	(void)more;
	if (signo == SIGUSR1)
		g_wait_ack = 0;
	else if (signo == SIGUSR2)
	{
		g_wait_ack = 0;
		write(1, "Message Sent!\n", 14);
	}
}

int	main(int argc, char *argv[])
{
	set_server_sigaction(handler, 0);
	if (argc != 3)
	{
		write(1, "Need more args.\n", 16);
		exit(EXIT_FAILURE);
	}
	while (*argv[2])
		send_bits(atoi(argv[1]), *argv[2]++);
	send_bits(atoi(argv[1]), *argv[2]);
	return (EXIT_SUCCESS);
}
