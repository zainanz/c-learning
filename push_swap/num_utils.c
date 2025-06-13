/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:48:43 by zali              #+#    #+#             */
/*   Updated: 2025/06/01 15:33:02 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	total;
	int		sign;
	char	*s;

	total = 0;
	sign = 1;
	s = (char *)str;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		total *= 10;
		total += *s - '0';
		if (total * sign < INT_MIN || total * sign > INT_MAX)
			handle_str_error(NULL);
		s++;
	}
	return (total * sign);
}

int	valid_num(char *str)
{
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if ((*(str - 1) == '-' || *(str - 1) == '+') && (*str == ' '
			|| *str == '\0'))
		return (0);
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}
