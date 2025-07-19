/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:25:51 by zali              #+#    #+#             */
/*   Updated: 2025/07/19 14:25:52 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!ptr || !s1 || !s2)
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

char	*ft_strcpy(char *dest, char *src)
{
	char	*dest_start;

	dest_start = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_start);
}

int	safe_fork(void)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	*safe_malloc(int size)
{
	char	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	return ((void *)ptr);
}
