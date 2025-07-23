/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:40:28 by zali              #+#    #+#             */
/*   Updated: 2025/07/22 22:13:54 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	main(int argc, char *argv[], char *envp[])
{
	char		*ptr;
	char		*user_prompt;
	char		buffer[1000];
	char		*user;

	user = getenv("USER");
	if (user)
		user_prompt = ft_strjoin(getenv("USER"), "> ");
	else
		user_prompt = ft_strjoin(getcwd(buffer, 1000), ": ");
	while (ptr = readline(user_prompt))
	{
		if (!ft_strcmp(ptr, "exit"))
			break ;
		if (safe_fork() == 0)
			run_cmd(ptr, envp);
		wait(0);
		add_history(ptr);
		free(ptr);
		ptr = NULL;
	}
	rl_clear_history(); 
	free(user_prompt);
}
