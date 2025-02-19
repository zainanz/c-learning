/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:29:48 by zali              #+#    #+#             */
/*   Updated: 2025/02/18 12:10:31 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *destination, const char *source, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*source)
			destination[i] = *(source++);
		else
			destination[i] = '\0';
		i++;
	}
	destination[i] = '\0';
	return (destination);
}
