/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:15:29 by zali              #+#    #+#             */
/*   Updated: 2025/06/05 19:30:44 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
	int	ascii;

	ascii = (n % 10) + 48;
	if (n < 10)
		write(1, &ascii, 1);
	else
	{
		ft_putnbr(n / 10);
		write(1, &ascii, 1);
	}
}

void	set_server_sigaction(void *handler, int sig_handler)
{
	struct sigaction	sa;

	if (sig_handler)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
	}
	else
		sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}
