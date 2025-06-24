/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_handler_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 16:09:47 by zali              #+#    #+#             */
/*   Updated: 2025/06/24 16:13:39 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	malloc_error(void)
{
	write(2, "Malloc Error\n", 13);
	exit(EXIT_FAILURE);
}

void	msg_recieved(pid_t pid)
{
	safe_kill(pid, SIGUSR2);
}

void	send_ack(pid_t pid)
{
	safe_kill(pid, SIGUSR1);
}

int	char_handler(int signo, int sender_pid)
{
	static char	c;
	static int	bits;

	if (signo == SIGUSR1)
		c |= (128 >> bits);
	else if (signo == SIGUSR2)
		c &= ~(128 >> bits);
	bits++;
	if (bits >= 8)
	{
		bits = 0;
		if (c == '\0')
		{
			string_end();
			msg_recieved(sender_pid);
			return (0);
		}
		append_to_string(c);
	}
	send_ack(sender_pid);
	return (1);
}

int	len_handler(int signo, int sender_pid)
{
	static int	size;

	if (signo == SIGUSR1)
	{
		size++;
		send_ack(sender_pid);
		return (0);
	}
	if (signo == SIGUSR2)
	{
		msg_recieved(sender_pid);
		string_init(size);
		size = 0;
		return (1);
	}
	return (0);
}
