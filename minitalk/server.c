/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:11:08 by zali              #+#    #+#             */
/*   Updated: 2025/06/24 16:13:34 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int signo, siginfo_t *info, void *more)
{
	static int		have_size;
	static pid_t	sender_pid;

	(void)more;
	if (info->si_pid)
		sender_pid = info->si_pid;
	if (!have_size)
	{
		have_size = len_handler(signo, sender_pid);
		return ;
	}
	have_size = char_handler(signo, sender_pid);
}

int	main(void)
{
	set_server_sigaction(sig_handler, 1);
	write(1, "Server running PID: ", 20);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
}
