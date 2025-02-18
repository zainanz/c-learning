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

void	*ft_memmove(void *destination, const void *source, size_t num)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = ft_strdup((char *)source);
	if (ft_strlen(destination) < num || ft_strlen(cpy) < num)
		return (NULL);
	while (i < num)
	{
		((char *)destination)[i] = ((char *)cpy)[i];
		i++;
	}
	free(cpy);
	return (destination);
}
