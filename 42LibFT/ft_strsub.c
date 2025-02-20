/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 19:26:28 by zali              #+#    #+#             */
/*   Updated: 2025/02/20 19:49:48 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;
	unsigned int	size;

	i = 0;
	size = len - start;
	ptr = ft_strnew(size);
	if (!ptr)
		return (NULL);
	while (i < size)
	{
		ptr[i] = s[start + i];
		i++;
	}
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
