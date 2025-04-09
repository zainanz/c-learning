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

static int	is_in_set(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	get_end(const char *s1, const char *set)
{
	ssize_t	len;

	len = ft_strlen((char *)s1) - 1;
	while (len >= 0)
	{
		if (!is_in_set(set, s1[len]))
			return (len + 1);
		len--;
	}
	return (0);
}

static int	get_start(const char *s1, const char *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!is_in_set(set, s1[i]))
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

/* int main(int argc, char **argv)
{
	// ft_strtrim: Remove os separadores fornecidos de uma str
	// no seu inicio e final.
	if (argc == 3)
	{
		printf("ft_strtrim: %s\n", ft_strtrim(argv[1], argv[2]));
	}
	return (0);
} */
/*
char	*ft_strtrim(char *s)
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
*/
