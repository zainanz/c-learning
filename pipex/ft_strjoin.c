/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:46:15 by zali              #+#    #+#             */
/*   Updated: 2025/06/07 18:46:22 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!ptr || !s1 || !s2)
		return (NULL);
	if (s1)
		while (*s1)
			ptr[i++] = *s1++;
	if (s2)
		while (*s2)
			ptr[i++] = *s2++;
	ptr[i] = '\0';
	return (ptr);
}
