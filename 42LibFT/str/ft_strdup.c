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
	int		s_len;
	char	*s_cpy;
	char	*start;

	s_len = ft_strlen((char *)s);
	s_cpy = malloc(s_len * sizeof(char));
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
