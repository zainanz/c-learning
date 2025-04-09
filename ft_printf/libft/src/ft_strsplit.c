/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:33:16 by zali              #+#    #+#             */
/*   Updated: 2025/02/21 09:47:06 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_word_len(char *s, char c)
{
	int	len;

	len = 0;
	while (*s == c)
		s++;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

char	*ft_get_word(char *s, char c)
{
	int		len;
	char	*str;

	len = ft_get_word_len(s, c);
	if (len == 0)
		return (NULL);
	while (*s == c)
		s++;
	str = ft_strnew(len);
	ft_strncpy(str, (const char *)s, len);
	return (str);
}

char	**ft_strsplit(char const *s, char c)
{
	int		total_words;
	int		i;
	char	**strs;

	total_words = ft_count_words((char *)s, c);
	strs = malloc(sizeof(char *) * (total_words + 1));
	i = 0;
	while (*s)
	{
		strs[i] = ft_get_word((char *)s, c);
		while (*s == c)
			s++;
		i++;
		s = s + ft_get_word_len((char *)s, c);
	}
	strs[i] = NULL;
	return (strs);
}
/*
#include <stdio.h>
int	main(void)
{
	char text[] = "          my work is done here.     ";
	char **strs = ft_strsplit(text, ' ');
	while (*strs)
	{
		printf("%s\n", *strs);
		strs++;
	}
}
*/
// " my work is done h."
// 5 total_words
// Allocated 6 Char *
//
