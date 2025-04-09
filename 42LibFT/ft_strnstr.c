/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:09:39 by zali              #+#    #+#             */
/*   Updated: 2025/04/08 13:02:23 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *s1, char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*s2)
		return (s1);
	while (s1[i])
	{
		j = 0;
		while (s2[j] && s1[i + j] == s2[j] && (i + j) < len)
			j++;
		if (s2[j] == 0)
			return (&s1[i]);
		i++;
	}
	return (0);
}
