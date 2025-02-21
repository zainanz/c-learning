/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:04:43 by zali              #+#    #+#             */
/*   Updated: 2025/02/21 09:18:08 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iswhitespace(int c)
{
	return ((c == ' ' || c == '\t' || c == '\n'));
}

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*ptr;

	start = 0;
	i = 0;
	end = ft_strlen((char *)s) - 1;
	while (ft_iswhitespace(s[start]))
		start++;
	while (ft_iswhitespace(s[end]))
		end--;
	ptr = ft_strnew(end - start + 1);
	if (!ptr)
		return (NULL);
	while (start <= end)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
