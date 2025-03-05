/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:14:00 by zali              #+#    #+#             */
/*   Updated: 2025/03/05 18:04:23 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_print_str(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		ft_putchar(str[count++]);
	return (count);
}

int	ft_print_int(int nbr)
{
	ft_putnbr(nbr);
	return (sizeof(int));
}

int	ft_print_mem(void *ptr) {
	int 		i;
	char 		*HEX;
	unsigned int 	val;
	unsigned int	leading_z;

	HEX = "0123456789abcdef";
	i = 7;
	leading_z = 1;
	write(1, "0x", 2);
	while (i >= 0) {
		val = ((unsigned char *)&ptr)[i--];
		if (leading_z && val == 0)
			continue;
		ft_putchar(HEX[val / 16]);
		ft_putchar(HEX[val % 16]);
		leading_z = 0;
	}
	return (8);
}

int	ft_display_params(va_list args, char c)
{
	int	size;

	size = 0;
	if (c == 's')
		size = ft_print_str(va_arg(args, char *));
	else if (c == 'i' || c == 'd')
		size = ft_print_int(va_arg(args, int));
	else if (c == 'u')
		size = ft_print_int(va_arg(args, unsigned int));
	else if (c == 'p')
		size = ft_print_mem(va_arg(args, void *));
//	else if (c == 'x' || c == 'X')
//		size = ft_print_hex(va_arg(args, int));
//	else if (c == '%')
//		size = write(1, "%", 1);
	return (size);
}

int	ft_printf(char *str, ...)
{
	va_list	args;
	int	i;
	int	total_bytes;

	va_start(args, str);
	i = 0;
	total_bytes = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			total_bytes += ft_display_params(args, str[++i]);
		}
		else
		{
			ft_putchar(str[i]);
			total_bytes++;
		}
		i++;
	}
	va_end(args);
	return (total_bytes);
}

#include <stdio.h>
int	main(void)
{
	char name[] = "zainan";
	int byte_size = ft_printf("FT_PRINTF: %p\t - ", name);
	ft_printf("%i\n", byte_size);
	printf("PRINTF: %p\n", name);
}
