/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:27:06 by zali              #+#    #+#             */
/*   Updated: 2025/02/22 15:45:10 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_neutralize_n(int n)
{
	n /= 10;
	n *= -1;
	return (n);
}

char	*ft_itoa(int n)
{
	int		neg;
	int		len;
	char	*str;

	neg = 0;
	if (n < 0)
		neg = 1;
	len = ft_total_digits(n);
	str = ft_strnew(len + neg + 1);
	if (!str)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (neg)
	{
		str[len] = (((long int)n * -1) % 10) + '0';
		n = ft_neutralize_n(n);
		str[0] = '-';
	}
	while (n)
	{
		str[--len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(0));
}
*/
