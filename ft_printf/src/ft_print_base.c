/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:36:20 by zali              #+#    #+#             */
/*   Updated: 2025/03/13 15:36:46 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex_with_upcase(int c, int upcase)
{
	if (upcase)
		ft_putchar(ft_toupper(c));
	else
		ft_putchar(c);
}

int	ft_print_base(long int nbr, int upcase, int base)
{
	int	sum;

	sum = 0;
	if (nbr < 0)
	{
		sum = write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr < base)
	{
		ft_print_hex_with_upcase(HEX[nbr], upcase);
		return (1);
	}
	sum += ft_print_base(nbr / base, upcase, base) + 1;
	ft_print_hex_with_upcase(HEX[nbr % base], upcase);
	return (sum);
}

int	ft_base_size(long int nbr, int upcase, int base)
{
	int	sum;

	sum = 0;
	if (nbr < 0)
		nbr *= -1;
	if (nbr < base)
		return (1);
	sum += ft_base_size(nbr / base, upcase, base) + 1;
	return (sum);
}
