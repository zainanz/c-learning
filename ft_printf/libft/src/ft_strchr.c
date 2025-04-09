/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:37:24 by zali              #+#    #+#             */
/*   Updated: 2025/02/16 16:47:57 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *str, int search_str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)search_str)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)search_str == '\0')
		return ((char *)str + i);
	return (0);
}
