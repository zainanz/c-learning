/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 07:01:15 by zali              #+#    #+#             */
/*   Updated: 2025/02/17 07:44:57 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *destination, const char *source, size_t num)
{
	char	*start;
	size_t	i;

	i = 0;
	start = destination;
	while (*destination)
		destination++;
	while (source[i] && i < num)
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return (start);
}
