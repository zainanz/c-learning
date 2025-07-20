/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:47:04 by zali              #+#    #+#             */
/*   Updated: 2025/07/20 14:49:33 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putstr_fd(int fd, char *str)
{
	size_t	i;

	i = ft_strlen(str);
	write(fd, str, i);
	write(fd, "\n", 1);
	return ((int) i);
}