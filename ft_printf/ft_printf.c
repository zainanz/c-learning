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
		size = ft_print_base(va_arg(args, int), 0, 10);
	else if (c == 'u')
		size = ft_print_base(va_arg(args, unsigned int), 0, 10);
	else if (c == 'c')
		size = ft_print_char(va_arg(args, int));
	else if (c == 'p')
		size = ft_print_mem(va_arg(args, void *));
	else if (c == 'x' || c == 'X')
		size = ft_print_base(va_arg(args, unsigned int), c == 'X', 16);
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
