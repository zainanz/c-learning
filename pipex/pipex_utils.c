/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:54:40 by zali              #+#    #+#             */
/*   Updated: 2025/06/07 18:55:02 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>

void	open_files(int *fd, char *argv[])
{
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[4], O_WRONLY | O_CREAT, 0777);
	if (fd[0] < 0 || fd[1] < 0)
	{
		perror("open error");
		exit(EXIT_FAILURE);
	}
}

void	run_process(char *str)
{
	char	**args;
	char	*path;

	args = ft_split(str, ' ');
	path = ft_strjoin("/bin/", args[0]);
	execve(path, args, NULL);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

void	pid1_exec(int *fd, int *pipefd, char *cmd)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close_files(fd, pipefd);
	run_process(cmd);
}

void	pid2_exec(int *fd, int *pipefd, char *cmd)
{
	dup2(fd[1], STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	close_files(fd, pipefd);
	run_process(cmd);
}

void	close_files(int *fd, int *pipefd)
{
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd[0]);
	close(fd[1]);
}
