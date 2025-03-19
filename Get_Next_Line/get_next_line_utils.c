/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:05:03 by zali              #+#    #+#             */
/*   Updated: 2025/03/19 12:23:27 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int search_str)
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
		return (str + i);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
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
/*
char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	c;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	str = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	c = -1;
	while (s2[++c])
		str[i + c] = s2[c];
	str[i + c] = '\0';
	free(s1);
	return (str);
}
*/
