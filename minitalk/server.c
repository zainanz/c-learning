/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:11:08 by zali              #+#    #+#             */
/*   Updated: 2025/06/05 19:45:05 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	msg_recieved(pid_t pid)
{
	write(1, "completed.\n", 11);
	kill(pid, SIGUSR2);
}

void	send_ack(pid_t pid)
{
	write(1, "ack sent\n", 9);
	kill(pid, SIGUSR1);
}

void	sig_handler(int signo, siginfo_t *info, void *more)
{
	static int		bits;
	static char		c;
	static pid_t	sender_pid;

	if (info->si_pid)
		sender_pid = info->si_pid;
	if (signo == SIGUSR1)
		c |= 0b10000000 >> bits;
	else if (signo == SIGUSR2)
		c &= ~(0b10000000 >> bits);
	bits++;
	if (bits == 8)
	{
		bits = 0;
		if (c == '\0')
		{
			write(1, "\n", 1);
			msg_recieved(sender_pid);
			return ;
		}
		else
			write(1, &c, 1);
	}
	send_ack(sender_pid);
}

int	main(void)
{
	set_server_sigaction(sig_handler, 1);
	ft_putnbr(getpid());
	while (1)
		pause();
}
