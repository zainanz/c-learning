/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:30:06 by zali              #+#    #+#             */
/*   Updated: 2025/07/20 17:17:34 by zali             ###   ########.fr       */
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

/*
	Testing function  
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
*/

void	free_trees(t_cmd *cmd)
{
	if (cmd->type == EXEC)
	{
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
}