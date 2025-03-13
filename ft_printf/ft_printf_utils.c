/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 15:00:53 by zali              #+#    #+#             */
/*   Updated: 2025/03/13 11:40:55 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str, t_print_data *data)
{
	int	count;
	int	str_len;

	str_len = ft_strlen(str);
	count = 0;
	if (!data->left_just && data->width > str_len)
		ft_add_char(' ', data->width - str_len);
	while (str[count])
		ft_putchar(str[count++]);
	if (data->left_just && data->width > str_len)
		ft_add_char(' ', data->width - str_len);
	if (data->width > str_len)
		count += data->width - str_len;
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
	int	size;

	size = sizeof(char);
	if (data->width > sizeof(char) && !data->left_just)
		ft_add_char(' ', data->width - sizeof(char));
	ft_putchar(c);
	if (data->width > sizeof(char) && data->left_just)
		ft_add_char(' ', data->width - sizeof(char));
	if (data->width > sizeof(char))
		size += data->width - sizeof(char);
	return (size);
}
int	ft_print_base(long int nbr, int upcase, int base, t_print_data *data)
{
	int	total_bytes;

	total_bytes = 0;
	if (data->sign)
	{
		if (nbr > 0)
		{
			write(1, "+", 1);
		}
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr *= -1;
		}
		total_bytes++;
	}
	if (data->width > ft_total_digits(nbr) && !data->left_just)
	{
		if (data->zero)
			ft_add_char('0', data->width - (ft_total_digits(nbr) + total_bytes));
		else
			ft_add_char(' ', data->width - (ft_total_digits(nbr) + total_bytes));
	}
	total_bytes += ft_print_base_core(nbr, upcase, base);
	if (data->width > ft_total_digits(nbr) && data->left_just)
		ft_add_char(' ', data->width - total_bytes);
	if (data->width > total_bytes)
		total_bytes += data->width - total_bytes;
	return (total_bytes);
}

int	ft_print_base_core(long int nbr, int upcase, int base)
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
	sum += ft_print_base_core(nbr / base, upcase, base) + 1;
	ft_print_hex_with_upcase(HEX[nbr % base], upcase);
	return (sum);
}
