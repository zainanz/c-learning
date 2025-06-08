/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_close.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 22:11:08 by zali              #+#    #+#             */
/*   Updated: 2025/06/07 22:21:50 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <unistd.h>

void	free_array_strings(char *args[])
{
	int	i;

	i = 0;
	while (args && args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	close_files(int *fd, int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd[0]);
	close(fd[1]);
}

void	dup_failure(void)
{
	perror("dup2 failure");
	exit(EXIT_FAILURE);
}
