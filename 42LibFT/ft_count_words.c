/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:46:39 by zali              #+#    #+#             */
/*   Updated: 2025/02/21 20:07:03 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_words(char *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
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
/*
#include <stdio.h>
int	main(void)
{
	char text[] = "        my my name is    zainan    ";
	printf("%i\n", ft_count_words(text, ' '));
}
*/
