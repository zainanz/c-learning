/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:12:26 by zali              #+#    #+#             */
/*   Updated: 2025/02/19 13:53:01 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = malloc(size);
	if (!ptr || size == 0)
	{
		free(ptr);
		return (NULL);
	}
	ft_memset((void *)ptr, '\0', size);
	return (ptr);
}
