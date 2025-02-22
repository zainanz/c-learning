/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:16:01 by zali              #+#    #+#             */
/*   Updated: 2025/02/22 16:02:56 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long int	ln;
	int			offset;

	ln = n;
	offset = ft_pow(10, ft_total_digits(n) - 1);
	if (ln < 0)
	{
		write(1, "-", 1);
		ln *= -1;
	}
	while (offset)
	{
		ft_putchar(((ln / offset) % 10) + 48);
		offset = offset / 10;
	}
}
