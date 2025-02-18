/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:26:14 by zali              #+#    #+#             */
/*   Updated: 2025/02/18 12:43:00 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		((char *)destination)[i] = ((char *)source)[i];
		if (((char *)source)[i] == (char)c)
			return (destination + i + 1);
		i++;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char name[] = "zainaaa ali";
	char name2[] = "zayann";
	char *ptr = (char *)ft_memccpy(name, name2, 0, 12);
	printf("%s\n", ptr);
	printf("%s\n", name);
}*/
