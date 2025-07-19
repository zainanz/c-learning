/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:30:06 by zali              #+#    #+#             */
/*   Updated: 2025/07/19 18:05:51 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	nullify(t_cmd *cmd)
{
	int	i;
	t_redircmd *redircmd;
	t_pipecmd *pipecmd;
	t_execcmd *execcmd;

	i = 0;
	if (cmd == NULL)
		return ;
	if (cmd->type == EXEC)
	{
		execcmd = (t_execcmd *)cmd;
		while (execcmd->eargv[i])
			*execcmd->eargv[i++] = 0;
		return ;
	}
	if (cmd->type == PIPE)
	{
		pipecmd = (t_pipecmd *)cmd;
		nullify(pipecmd->left);
		nullify(pipecmd->right);
		return ;
	}
	if (cmd->type == REDIR)
	{
		redircmd = (t_redircmd *)cmd;
		nullify(redircmd->link);
		*redircmd->end_file = '\0';
		return ;
	}
}

int	char_presence(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}	

void	skip_whitespace(char **start, char *end)
{
	while (*start < end && char_presence(**start, " \t\r\n\v"))
		*start = *start + 1;
}

static char	update_and_get_token(char **str, char *end_str)
{
	char	ret;

	ret = **str;
	if (char_presence(**str, "<>|()&\0"))
	{
		if (*(*str + 1) == '>' && **str == '>')
			ret = '+';
		else if (*(*str + 1) == '<' && **str == '<')
			ret = '-';
		else if (*(*str + 1) == '|' && **str == '|')
			ret = 'o';
		else if (*(*str + 1) == '&' && **str == '&')
			ret = 'a';
		else
			(*str)--;
		*str = *str + 2;
	}
	else
	{
		ret = 'w';
		while (*str < end_str && !char_presence(**str, " \t\r\n\v")
		&& !char_presence(**str, "<>|()&"))
			(*str)++;
	}
	return (ret);
}

char	get_token(char **str, char *end_str, char **ptr, char **end_ptr)
{
	char	token;

	skip_whitespace(str, end_str);
	if (ptr)
		*ptr = *str;
	token = update_and_get_token(str, end_str);
	if (end_ptr)
		*end_ptr = *str;
	skip_whitespace(str, end_str);	
	return (token);
}

int	ft_exists_wskip(char **str, char *end_str, char *set)
{
	skip_whitespace(str, end_str);
	return (char_presence(**str, set));
}


t_execcmd	*init_t_execcmd(void)
{
	t_execcmd	*execcmd;

	execcmd = malloc(sizeof(*execcmd));
	memset(execcmd, 0, sizeof(*execcmd)); // Make your own
	execcmd->type = EXEC;
	return (execcmd);
}


t_cmd	*redir(t_cmd *cmd, char *sfile, char *efile, int mode, int fd)
{
	t_redircmd	*redircmd;

	redircmd = malloc(sizeof(*redircmd));
	if (!redircmd)
	{
		perror("Malloc error");
		exit(EXIT_FAILURE);
	}
	redircmd->type = REDIR;
	redircmd->link = cmd;
	redircmd->file = sfile;
	redircmd->end_file = efile;
	redircmd->mode = mode;
	redircmd->fd = fd;
	
	return ((t_cmd *)redircmd);
}

t_cmd	*parseredirects(t_cmd *cmd, char **str, char *end_str)
{
	char	token;
	char	*ptr;
	char	*ptr_end;

	token = 0;
	ptr = NULL;
	ptr_end = NULL;
	while (ft_exists_wskip(str, end_str, "<>"))
	{
		
		token = get_token(str, end_str, 0, 0);
		if (get_token(str, end_str, &ptr, &ptr_end) != 'w')
			exit(EXIT_FAILURE); //prev token = < or > now looking for '> FILENAME' - if !word after skipping space filename missing
		if (token == '<') // <
			cmd = redir(cmd, ptr, ptr_end, O_RDONLY, 0);
		else if (token == '>') // >
			cmd = redir(cmd, ptr, ptr_end, O_WRONLY | O_TRUNC | O_CREAT, 1);
		else if (token == '+') // >>
			cmd = redir(cmd, ptr, ptr_end, O_WRONLY | O_CREAT, 1);
		else if (token == '-') // <<
			cmd = redir(cmd, ptr, ptr_end, O_WRONLY | O_CREAT, 0);
	}
	return (cmd);
}

t_cmd	*parsestr(char **str, char *end_str)
{
	int			argc;
	t_execcmd	*exec_cmd;
	t_cmd		*ret;
	int			token;
	char		*ptr;
	char		*end_ptr;

	argc = 0;
	exec_cmd = init_t_execcmd();
	ret = (t_cmd *) exec_cmd; 
	ret = parseredirects(ret, str, end_str); 
	while (!ft_exists_wskip(str, end_str, "<>|()&") && *str < end_str)
	{
		token = get_token(str, end_str, &ptr, &end_ptr);
		int i = 0;
		
		if (!token)
			break ;
		exec_cmd->argv[argc] = ptr; 
		exec_cmd->eargv[argc] = end_ptr; 
		argc++;
		if (argc >= MAX_SIZE)
			exit(EXIT_FAILURE); // Proper exit func
		ret = parseredirects(ret, str, end_str); 
	}
	exec_cmd->argv[argc] = 0;
	exec_cmd->eargv[argc] = 0;
	return (ret);
}

t_cmd	*init_t_pipecmd(t_cmd *left, t_cmd *right)
{
	t_pipecmd	*pipecmd;

	pipecmd = malloc(sizeof(*pipecmd));
	pipecmd->left = left;
	pipecmd->right = right;
	pipecmd->type = PIPE; 
	return ((t_cmd *)pipecmd);
}

t_cmd	*parsepipe(char **str, char *end_str)
{
	char	*s;
	t_cmd	*cmd;

	s = *str;
	cmd = parsestr(str, end_str);
	if (ft_exists_wskip(str, end_str, "|"))
	{
		get_token(str, end_str, 0, 0);
		cmd = init_t_pipecmd(cmd, parsepipe(str, end_str));
	}
	return (cmd);
}

t_cmd	*parsecmd(char *str, char *end_str)
{
	t_cmd	*cmd;

	cmd = parsepipe(&str, end_str);
	nullify(cmd);
	return (cmd);
}

void	show_cmd_tree(t_cmd *cmd)
{
	int	i;
	i = 0;

	if (cmd->type == EXEC)
	{
		printf("exec.\n");
		while (((t_execcmd *)cmd)->argv[i])
			printf("%s ", ((t_execcmd *)cmd)->argv[i++]);
		printf("\n");
		return ;
	}
	if (cmd->type == PIPE)
	{
		printf("pipe left.\n");
		show_cmd_tree(((t_pipecmd *)cmd)->left);
		printf("---------Left ends--------------\n");
		printf("pipe right.\n");
		show_cmd_tree(((t_pipecmd *)cmd)->right);
		return ;
	}
	if (cmd->type == REDIR)
	{
		printf("redir.\n");
		printf("filename: %s\n", ((t_redircmd *)cmd)->file);
		show_cmd_tree(((t_redircmd *)cmd)->link);
		return ;
	}
}

void pipe_recursive(t_cmd *cmd, char **envp);

void	exec_tree(t_cmd *cmd, char **envp)
{
	t_redircmd	*redircmd;
	t_execcmd	*execcmd;
	char		*cmd_path;
	
	if (cmd->type == EXEC)
	{
		execcmd = (t_execcmd *)cmd;
		cmd_path = ft_strjoin("/bin/", execcmd->argv[0]); 	
		execve(cmd_path, execcmd->argv, envp);
		free(cmd_path);
		printf("exeve failed.\n");
		return ;
	}
	if (cmd->type == PIPE)
	{
		pipe_recursive(cmd, envp);
		return ;
	}
	if (cmd->type == REDIR)
	{
		redircmd = (t_redircmd *)cmd;
		close(redircmd->fd);
		if (open(redircmd->file, redircmd->mode) < 0)
			exit(EXIT_FAILURE);
		exec_tree(((t_redircmd *)cmd)->link, envp);
		return ;
	} 
}

void pipe_recursive(t_cmd *cmd, char **envp)
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

void	free_trees(t_cmd *cmd)
{
	if (cmd->type == EXEC)
	{
		printf("cleans up exec.\n");
		free(cmd);
		cmd = NULL;
		return ;
	}
	if (cmd->type == REDIR)
	{
		free_trees(((t_redircmd *)cmd)->link);
		free(cmd);
		cmd = NULL;
		return ;
	}
	if (cmd->type == PIPE)
	{
		free_trees(((t_pipecmd *)cmd)->left);
		free_trees(((t_pipecmd *)cmd)->right);
		free(cmd);
		cmd = NULL;
		return ;
	}
}

void	run_cmd(char *str, char **envp)
{
	t_cmd	*cmd;	
	char	*end_str;

	end_str = str + ft_strlen(str);
	cmd = parsecmd(str, end_str);
	exec_tree(cmd, envp);
	free_trees(cmd);
	//show_cmd_tree(cmd);
}