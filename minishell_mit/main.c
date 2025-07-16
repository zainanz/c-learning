/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:40:28 by zali              #+#    #+#             */
/*   Updated: 2025/07/16 14:02:30 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	//run_cmd(strdup("< asd ls | cat"));

	char		*ptr;

	while (ptr = readline("zali> "))
	{
		// bultin_commands(ptr); - custom built commands
		//printf("%s\n", ptr);
		if (safe_fork() == 0)
		run_cmd(ptr);
		wait(0);
		add_history(ptr);
			free(ptr);
		ptr = NULL;
	}
}