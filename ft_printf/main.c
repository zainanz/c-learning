/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 15:50:34 by zali              #+#    #+#             */
/*   Updated: 2025/03/13 11:42:29 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int size = ft_printf("%#X\n", 0);
	ft_printf("SIZE: %i\n", size);
	char name[] = "zainan";
	size = printf("%#X\n", 0);
	printf("SIZE: %i\n", size);
}
