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

volatile sig_atomic_t	g_wait_ack = 1;

void	wait_ack(void)
{
	int	wait_time;

	wait_time = 0;
	while (g_wait_ack)
	{
		usleep(10);
		wait_time += 10;
		if (wait_time > 1000 && g_wait_ack)
		{
			write(1, "ERROR\n", 6);
			exit(EXIT_FAILURE);
		}
	}
}

void	send_bits(int sender_pid, char c)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		g_wait_ack = 1;
		if (c & (0b10000000 >> bits))
			safe_kill(sender_pid, SIGUSR1);
		else
			safe_kill(sender_pid, SIGUSR2);
		bits++;
		wait_ack();
	}
}

void	send_len(int sender_pid, char *str)
{
	while (*str)
	{
		g_wait_ack = 1;
		safe_kill(sender_pid, SIGUSR1);
		wait_ack();
		str++;
	}
	g_wait_ack = 1;
	safe_kill(sender_pid, SIGUSR2);
	wait_ack();
	write(1, "Sent Len\n", 9);
}

void	handler(int signo)
{
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
	int	sender_pid;

	set_server_sigaction(handler, 0);
	if (argc != 3)
	{
		write(1, "ERROR\n", 6);
		exit(EXIT_FAILURE);
	}
	sender_pid = ft_atoi(argv[1]);
	if (sender_pid <= 0 || sender_pid > INT_MAX)
	{
		write(1, "ERROR\n", 6);
		exit(EXIT_FAILURE);
	}
	send_len(sender_pid, argv[2]);
	while (*argv[2])
		send_bits(sender_pid, *argv[2]++);
	send_bits(sender_pid, *argv[2]);
	return (EXIT_SUCCESS);
}
