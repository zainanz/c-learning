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

size_t	ft_strlcpy(char *destination, const char *source, size_t n)
{
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = 0;
	if (!source)
		return (0);
	s_len = ft_strlen((char *)source);
	if (!n)
		return (s_len);
	while (source[i] != '\0' && (i < (n - 1)))
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return (s_len);
}
