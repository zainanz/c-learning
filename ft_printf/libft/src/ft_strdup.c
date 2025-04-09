/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:39:56 by zali              #+#    #+#             */
/*   Updated: 2025/02/17 12:50:05 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_cpy;
	char	*start;

	s_cpy = malloc(ft_strlen((char *)s) * sizeof(char) + 1);
	if (!s_cpy)
		return (NULL);
	start = s_cpy;
	while (*s)
	{
		*s_cpy = *s;
		s++;
		s_cpy++;
	}
	*s_cpy = '\0';
	return (start);
}
