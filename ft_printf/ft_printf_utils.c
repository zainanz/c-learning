/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:00:53 by zali              #+#    #+#             */
/*   Updated: 2025/03/08 08:06:34 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		ft_putchar(str[count++]);
	return (count);
}

int	ft_print_mem(void *ptr)
{
	unsigned int	val;
	unsigned int	leading_z;
	int				i;

	i = 7;
	leading_z = 1;
	write(1, "0x", 2);
	while (i >= 0)
	{
		val = ((unsigned char *)&ptr)[i--];
		if (leading_z && val == 0)
			continue ;
		ft_putchar(HEX[val / 16]);
		ft_putchar(HEX[val % 16]);
		leading_z = 0;
	}
	return (14);
}

void	ft_print_hex_with_upcase(int c, int upcase)
{
	if (upcase)
		ft_putchar(ft_toupper(c));
	else
		ft_putchar(c);
}

int	ft_print_char(int c, t_print_data *data)
{
	ft_putchar(c);
	return (sizeof(char));
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
