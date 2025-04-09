/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 09:27:09 by zali              #+#    #+#             */
/*   Updated: 2025/04/09 09:30:43 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	len;
	size_t	i;

	i = 0;
	lst = malloc(sizeof(char *) * (ft_count_words((char *)s, c) + 1));
	if (!s || !lst)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		if (!ft_strchr(s, c))
			len = ft_strlen((char *)s);
		else
			len = ft_strchr(s, c) - s;
		lst[i++] = ft_substr(s, 0, len);
		s += len;
	}
	lst[i] = NULL;
	return (lst);
}
