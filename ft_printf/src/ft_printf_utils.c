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

	if (!str)
		str = "(null)";
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

int	ft_put_hex(uintptr_t n)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_put_hex(n / 16);
	ft_putchar(HEX[n % 16]);
	return (count + 1);
}

int	ft_print_mem(void *ptr)
{
	uintptr_t	addr;
	int			count;	

	count = 0;
	addr = (uintptr_t)ptr;
	if (!ptr)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += ft_put_hex(addr);
	return (count);
}

int	ft_print_char(int c, t_print_data *data)
{
	int	size;

	size = sizeof(char);
	if ((long unsigned int)data->width > sizeof(char) && !data->left_just)
		ft_add_char(' ', data->width - sizeof(char));
	ft_putchar(c);
	if ((long unsigned int)data->width > sizeof(char) && data->left_just)
		ft_add_char(' ', data->width - sizeof(char));
	if ((long unsigned int)data->width > sizeof(char))
		size += data->width - sizeof(char);
	return (size);
}

int	ft_print_base_core(long int nbr, int upcase, int base, t_print_data *data)
{
	int	total_bytes;

	total_bytes = 0;
	if (data->sign || data->space)
		total_bytes++;
	if ((data->sign || data->space) && data->zero)
		nbr = ft_add_sign(nbr, data);
	total_bytes += ft_base_size(nbr, upcase, base);
	if ((data->format == 'x' || data->format == 'X') && data->hashtag && nbr)
		total_bytes += 2;
	ft_add_char_if(data->width > total_bytes && !data->left_just, data->zero,
		data->width - total_bytes);
	if ((data->sign || data->space) && !data->zero)
		nbr = ft_add_sign(nbr, data);
	if ((data->format == 'x' || data->format == 'X') && data->hashtag && nbr)
		ft_display_hashtag_sign(upcase);
	ft_print_base(nbr, upcase, base);
	if (nbr < 0)
		total_bytes++;
	ft_add_char_if(data->width > total_bytes && data->left_just, 0,
		data->width - total_bytes);
	if (data->width > total_bytes)
		total_bytes += data->width - total_bytes;
	return (total_bytes);
}
