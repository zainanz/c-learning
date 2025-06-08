/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:01:03 by zali              #+#    #+#             */
/*   Updated: 2025/06/07 18:17:52 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
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
		return (ft_strnew(1));
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

static char	*ft_strchr(const char *str, int search_str)
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

static int	ft_count_words(char *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	if (!*s)
		return (0);
	while (s[i] == c)
		i++;
	if (s[i] != c || s[i] != '\0')
		words++;
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != '\0'))
			words++;
		i++;
	}
	return (words);
}

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
