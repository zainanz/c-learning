/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:26:28 by zali              #+#    #+#             */
/*   Updated: 2025/02/20 19:49:48 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	size;
	size_t			s_len;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen((char *)s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		size = s_len - start;
	else
		size = len;
	ptr = ft_strnew(size + 1);
	if (!ptr)
		return (NULL);
	while (i < size)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
#include <stdio.h>
int main(void)
{
	char intro[] = "my name is zainan";

	char *name = ft_strsub(intro, 11, 17);
	printf("%s\n", name);
}
*/
