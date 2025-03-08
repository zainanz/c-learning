/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:14:00 by zali              #+#    #+#             */
/*   Updated: 2025/03/08 07:58:35 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	else if (c == 'x' || c == 'X')
		size = ft_print_hex(va_arg(args, unsigned int), c == 'X');
	else if (c == '%')
		size = write(1, "%", 1);
	return (size);
}

int	ft_printf(char *str, ...)
{
	va_list	args;
	int		i;
	int		total_bytes;

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
/*
#include <stdio.h>
int	main(void)
{
	char name[] = "zainan";
	int size = printf("%x\n", 4222);
	printf("%i\n", size);
	size = ft_printf("%x\n", 4222);
	printf("%i\n", size);
//	size = printf("%p\n", name);
//	printf("%i\n", size);
}
*/
