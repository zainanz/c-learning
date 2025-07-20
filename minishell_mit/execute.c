/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:38:28 by zali              #+#    #+#             */
/*   Updated: 2025/07/20 17:33:05 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void pipe_recursive(t_cmd *cmd, char **envp);
static void exec_recursive(t_cmd *cmd, char **envp);
static void redir_recursive(t_cmd *cmd, char **envp);

void	exec_tree(t_cmd *cmd, char **envp)
{
	
	if (cmd->type == EXEC)
		exec_recursive(cmd, envp);
	else if (cmd->type == PIPE)
		pipe_recursive(cmd, envp);
	else if (cmd->type == REDIR)
		redir_recursive(cmd, envp);
}

static void exec_recursive(t_cmd *cmd, char **envp)
{
	t_execcmd	*execcmd;
	char		*str_ptr;

	execcmd = (t_execcmd *)cmd;
	str_ptr = ft_strjoin("/bin/", execcmd->argv[0]); 	
	execve(str_ptr, execcmd->argv, envp);
	free(str_ptr);
	execve(execcmd->argv[0], execcmd->argv, envp);
	if (execcmd->argv[0][0] == '.' && execcmd->argv[0][1] == '/')
		perror(execcmd->argv[0]);
	else
	{
		str_ptr = ft_strjoin(execcmd->argv[0], ": command not found\n"); 
		write(STDERR_FILENO, str_ptr, ft_strlen(str_ptr));
		free(str_ptr);
	}
	exit(EXIT_FAILURE);
}

static void	handle_heredoc(t_cmd *cmd)
{
	char		*ptr;
	int			hd_pipe[2];
	t_redircmd	*redircmd;

	if (pipe(hd_pipe) < 0)
		perror("pipe error");
	ptr = NULL;
	redircmd = (t_redircmd *) cmd;
	while (1)
	{
		ptr = readline("heredoc>");
		if (strcmp(ptr, redircmd->file) == 0) // ft_strcmp implement
			break ;
		write(hd_pipe[1], ptr, ft_strlen(ptr));
		write(hd_pipe[1], "\n", 1);
		free(ptr);
	}
	close(hd_pipe[1]);
	dup2(hd_pipe[0], 0);
	close(hd_pipe[0]);
}

static void redir_recursive(t_cmd *cmd, char **envp)
{
	t_redircmd	*redircmd;
	
	redircmd = (t_redircmd *)cmd;
	if (redircmd->redir_type == '-')
	{
		handle_heredoc(cmd);
	}
	else
	{
		close(redircmd->fd);
		if (open(redircmd->file, redircmd->mode) < 0)
		exit(EXIT_FAILURE);
	}
	exec_tree(((t_redircmd *)cmd)->link, envp);
}

static void pipe_recursive(t_cmd *cmd, char **envp)
{
	int	pipe_fd[2];

	if (pipe(pipe_fd) < 0)
		exit(EXIT_FAILURE);
	if (safe_fork() == 0)
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		close(pipe_fd[0]);
		exec_tree(((t_pipecmd *)cmd)->left, envp);
	}
	if (safe_fork() == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		exec_tree(((t_pipecmd *)cmd)->right, envp);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	wait(0);
	wait(0);
}
