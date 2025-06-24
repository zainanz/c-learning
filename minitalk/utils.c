/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:15:29 by zali              #+#    #+#             */
/*   Updated: 2025/06/24 16:10:33 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	safe_kill(int sender_pid, int signo)
{
	if (kill(sender_pid, signo) == -1)
	{
		write(2, "Kill Error\n", 11);
		exit(EXIT_FAILURE);
	}
}

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

int	ft_atoi(char *str)
{
	int	sign;
	int	total;

	sign = 1;
	total = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while (*str >= '0' && *str <= '9')
	{
		total *= 10;
		total += *str - 48;
		str++;
	}
	return (total * sign);
}

void	remove_garbage_value(void *str, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((char *)str)[i] = 0;
		i++;
	}
}

void	set_server_sigaction(void *handler, int sig_handler)
{
	struct sigaction	sa;

	remove_garbage_value(&sa, sizeof(sa));
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
