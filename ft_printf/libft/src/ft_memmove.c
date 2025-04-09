/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:13:55 by zali              #+#    #+#             */
/*   Updated: 2025/02/18 12:23:57 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t len)
{
	char	*cpy_dest;
	char	*cpy_src;
	size_t	i;

	cpy_src = (char *)source;
	cpy_dest = (char *)destination;
	i = 0;
	if (cpy_dest > cpy_src)
	{
		while (len-- > 0)
			cpy_dest[len] = cpy_src[len];
	}
	else
	{
		while (i < len)
		{
			cpy_dest[i] = cpy_src[i];
			i++;
		}
	}
	return (destination);
}
