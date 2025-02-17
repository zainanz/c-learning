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

char	*ft_strlcat(char *destination, const char *source, size_t num)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	dest_size = ft_strlen(destination);
	src_size = ft_strlen(source);
	i = dest_size;
	while (*source && i + 1 < size)
	{
		destination[i] = *source;
		i++;
		source++;
	}
	destination[i] = '\0';
	if (dest_size > size)
		return (src_size + size);
	return (src_size + dest_size)
}

