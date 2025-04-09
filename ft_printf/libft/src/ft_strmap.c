/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:40:27 by zali              #+#    #+#             */
/*   Updated: 2025/02/19 13:43:01 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	int		i;

	ptr = ft_strnew(ft_strlen((char *)s));
	i = 0;
	if (!ptr || !f)
		return (NULL);
	while (s[i])
	{
		ptr[i] = f(s[i]);
		i++;
	}
	return (ptr);
}
