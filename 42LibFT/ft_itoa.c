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

char	*ft_itoa(int n)
{
	int		neg;
	int		len;
	char	*str;

	neg = 0;
	if (n < 0)
		neg = 1;
	len = ft_total_digits(n);
	str = ft_strnew(len + neg);
	if (!str)
		return (NULL);
	if (neg)
	{
		str[len] = (((long int)n * -1) % 10) + '0';
		n /= 10;
		n *= -1;
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
	printf("%s\n", ft_itoa(-123));
	printf("%s\n", ft_itoa(2147483647));
}*/
