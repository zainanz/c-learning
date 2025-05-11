/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 13:31:31 by zali              #+#    #+#             */
/*   Updated: 2025/04/25 14:06:49 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	string_test(char *text)
{
	int	size;

	printf(">----- %s -----<\n", text);
	ft_printf("ft_printf =>  ");
	size = ft_printf("%s", text);
	ft_printf("\n              ");
	ft_printf("%i", size);
	ft_printf("\n");
	printf("printf    =>  ");
	size = printf("%s", text);
	printf("\n              ");
	printf("%i", size);
	printf("\n");
}


int	main(void)
{
	string_test("hello");
	string_test("");
	string_test("zainan");
	string_test(NULL);
	string_test(0);
}
