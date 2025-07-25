/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:54:40 by zali              #+#    #+#             */
/*   Updated: 2025/06/07 22:22:43 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <unistd.h>

void	open_files(int *fd, char *argv[])
{
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd[0] < 0)
		perror(argv[1]);
	if (fd[1] < 0)
		perror(argv[4]);
}

void	run_process(char *cmd_arg, char **envp)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(cmd_arg, ' ');
	if (cmd[0])
	{
		path = ft_strjoin("/bin/", cmd[0]);
		execve(path, cmd, envp);
		free(path);
		execve(cmd[0], cmd, envp);
	}
	write(STDERR_FILENO, "Command not found.\n", 19);
	free_array_strings(cmd);
	exit(127);
}

void	pid1_exec(int *fd, int *pipefd, char *cmd_arg, char **envp)
{
	if (dup2(fd[0], STDIN_FILENO) < 0)
		dup_failure();
	if (dup2(pipefd[1], STDOUT_FILENO) < 0)
		dup_failure();
	close_files(fd, pipefd);
	run_process(cmd_arg, envp);
}

void	pid2_exec(int *fd, int *pipefd, char *cmd_arg, char **envp)
{
	if (dup2(fd[1], STDOUT_FILENO) < 0)
		dup_failure();
	if (dup2(pipefd[0], STDIN_FILENO) < 0)
		dup_failure();
	close_files(fd, pipefd);
	run_process(cmd_arg, envp);
}
