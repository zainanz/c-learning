/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:14:00 by zali              #+#    #+#             */
/*   Updated: 2025/03/13 11:36:31 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_display_params(va_list args, t_print_data *data)
{
	int	size;

	size = 0;
	if (data->format == 's')
		size = ft_print_str(va_arg(args, char *), data);
	else if (data->format == 'i' || data->format == 'd')
		size = ft_print_base(va_arg(args, int), 0, 10, data);
	else if (data->format == 'u')
		size = ft_print_base(va_arg(args, unsigned int), 0, 10, data);
	else if (data->format == 'c')
		size = ft_print_char(va_arg(args, int), data);
	else if (data->format == 'p')
		size = ft_print_mem(va_arg(args, void *));
	else if (data->format == 'x' || data->format == 'X')
		size = ft_print_base(va_arg(args, unsigned int), data->format == 'X', 16, data);
	else if (data->format == '%')
		size = write(1, "%", 1);
	return (size);
}

int	ft_printf(char *str, ...)
{
	va_list		args;
	int		i;
	int		total_bytes;
	t_print_data	*data;

	va_start(args, str);
	i = 0;
	total_bytes = 0;
	data = NULL;
	while (str[i])
	{
		if (str[i] == '%')
		{
			data = ft_init_pdata();
			i += ft_data_parse(&str[i], data);
			//ft_display_data(data);
			total_bytes += ft_display_params(args, data);
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
	ft_printf("-----------Testing------------\n");
	// Printf
	printf("\nPrintf:\n\t");
	// -------------------------------//
	printf("--%%x--\n\t");
	int size = printf("%x\n", 422);
	printf("\t%i bytes\n", size);
	
	printf("\n\t--%%X--\n\t");
	size = printf("%X\n", 422);
	printf("\t%i bytes\n", size);
	
	printf("\n\t--%%X--\n\t");
	size = printf("%X\n", -422);
	printf("\t%i bytes\n", size);

	printf("\n\t--%%s--\n\t");
	size = printf("%s\n", "helloworld");
	printf("\t%i bytes\n", size);
	
	printf("\n\t--%%c--\n\t");
	size = printf("%c %c %c\n", 'h', 'i', '.');
	printf("\t%i bytes\n", size);
	
	printf("\n\t--%%i--\n\t");
	size = printf("%i %i %i\n", 42, -42, 42);
	printf("\t%i bytes\n", size);

	printf("\n\t--%%d--\n\t");
	size = printf("%d %d %d\n", 420, -420, 420);
	printf("\t%i bytes\n", size);
	
	printf("\n\t--%%u--\n\t");
	size = printf("%u\n", 42);
	printf("\t%i bytes\n", size);
	
	printf("\n\t--%%u--\n\t");
	size = printf("%u\n", -42);
	printf("\t%i bytes\n", size);
	
	printf("\n\t--%%p--\n\t");
	size = printf("%p\n", name);
	printf("\t%i bytes\n", size);
	// ------------------------------//
	// ft_printf
	// -----------------------------//
	ft_printf("\nFt_Printf:\n\t");
	
	ft_printf("--%%x--\n\t");
	size = ft_printf("%x\n", 422);
	printf("\t%i bytes\n", size);
	
	ft_printf("\n\t--%%X--\n\t");
	size = ft_printf("%X\n", 422);
	ft_printf("\t%i bytes\n", size);
	
	ft_printf("\n\t--%%X--\n\t");
	size = ft_printf("%X\n", -422);
	ft_printf("\t%i bytes\n", size);
	
	ft_printf("\n\t--%%s--\n\t");
	size = ft_printf("%s\n", "helloworld");
	ft_printf("\t%i bytes\n", size);
	
	ft_printf("\n\t--%%c--\n\t");
	size = ft_printf("%c %c %c\n", 'h', 'i', '.');
	ft_printf("\t%i bytes\n", size);
	
	ft_printf("\n\t--%%i--\n\t");
	size = ft_printf("%i %i %i\n", 42, -42, 42);
	ft_printf("\t%i bytes\n", size);
	
	ft_printf("\n\t--%%d--\n\t");
	size = ft_printf("%d %d %d\n", 420, -420, 420);
	ft_printf("\t%i bytes\n", size);
	
	ft_printf("\n\t--%%u--\n\t");
	size = ft_printf("%u\n", 42);
	ft_printf("\t%i bytes\n", size);
	
	ft_printf("\n\t--%%u--\n\t");
	size = ft_printf("%u\n", -42);
	ft_printf("\t%i bytes\n", size);
	
	ft_printf("\n\t--%%p--\n\t");
	size = ft_printf("%p\n", name);
	ft_printf("\t%i bytes\n", size);
	// -----------------------------//
	ft_printf("------------------------------\n");
}
*/
