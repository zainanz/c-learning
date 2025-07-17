/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:40:28 by zali              #+#    #+#             */
/*   Updated: 2025/07/17 15:09:42 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	main(int argc, char *argv[], char *envp[])
{
	char		*ptr;
	char 		**cpy_env;
	int			i;
	char		*user;

	i = 0;
	cpy_env = copy_env(envp);
	user = getenv("USER"); // username ' need to strjoin with a > or : for prompt'
	while (ptr = readline(user))
	{
		if (safe_fork() == 0)
			run_cmd(ptr);
		wait(0);
		add_history(ptr);
		free(ptr);
		ptr = NULL;
	}
}
