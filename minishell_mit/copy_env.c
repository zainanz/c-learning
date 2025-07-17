/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 14:35:35 by zali              #+#    #+#             */
/*   Updated: 2025/07/17 14:38:21 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_env(char **env)
{
	int		i;
	int		j;
	char	**cpy_env;

	i = 0;
	j = 0;
	while (env[i])
		i++;
	cpy_env = safe_malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		j = ft_strlen(env[i]);
		cpy_env[i] = safe_malloc(sizeof(char) * j + 1);
		ft_strcpy(cpy_env[i], env[i]);
		i++;
	}
	cpy_env[i] = NULL;
	return (cpy_env);
}

void	free_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		free(env[i]);
		env[i] = NULL;
		i++;
	}
	free(env);
	env = NULL;
}
