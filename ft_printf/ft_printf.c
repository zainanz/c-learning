/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:14:00 by zali              #+#    #+#             */
/*   Updated: 2025/03/04 15:13:23 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int	ft_printstr(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		ft_putchar(str[count++]);
	return (count);
}

int	ft_display_params(va_list args, char c)
{
	int	size;

	size = 1;
	if (c == 's')
	{
		size = ft_printstr(va_arg(args, char *));
	}
	else if (c == 'i')
	{
		ft_putnbr(va_arg(args, int));
		size = 4;
	}
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

int	main(void)
{
	char name[] = "zainan";
	int byte_size = ft_printf("hello world, %i.\n", 5);
	ft_printf("%i", byte_size);
}
