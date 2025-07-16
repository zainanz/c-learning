/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runcmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:30:06 by zali              #+#    #+#             */
/*   Updated: 2025/07/16 18:16:52 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// Helper string man

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
		{

			printf("%p (%c) - %p (%c) \n", execcmd->argv[i], *execcmd->argv[i], execcmd->eargv[i], *execcmd->eargv[i]);
			*execcmd->eargv[i] = 0;
			i++;
		}
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
			ret = 'u';
		else if (*(*str + 1) == '<' && **str == '<')
			ret = 'r';
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

// ----------------

t_execcmd	*init_t_execcmd(void)
{
	t_execcmd	*execcmd;

	execcmd = malloc(sizeof(*execcmd));
	memset(execcmd, 0, sizeof(*execcmd)); // Make your own
	execcmd->type = EXEC;
	return (execcmd);
}

// -----------------------------------

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
			cmd = redir(cmd, ptr, ptr_end, O_APPEND | O_CREAT, 1);
		else if (token == 'u') // >>
			cmd = redir(cmd, ptr, ptr_end, O_WRONLY | O_CREAT, 1);
		else if (token == 'r') // <<
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
	/*
	if (strchr(str, "(") parseblock();
	todo prioritize () first
	*/
	argc = 0;
	exec_cmd = init_t_execcmd();
	ret = (t_cmd *) exec_cmd; 
	ret = parseredirects(ret, str, end_str); 
	while (!ft_exists_wskip(str, end_str, "<>|()&") && *str < end_str)
	{
		token = get_token(str, end_str, &ptr, &end_ptr);
		int i = 0;
		/*while (ptr + i < end_ptr)
		{
			write(1, ptr + i, 1);
			i++;
		}*/
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

/*
	1. Passes string to parsepipe. 
	2. Nullify(cmd)
		reason we do it in the end is lets say we have something ls -l|cat -e which isnt properly spaced.. 
		when it reaches -l it goes to | and if we convert it to \0. we never treat the pipe as it was changed. but if we do it in the end
		we already created the struct and have everythjing we need so loossing | or anything else wont hurt.
*/
t_cmd	*parsecmd(char *str, char *end_str)
{
	t_cmd	*cmd;

	cmd = parsepipe(&str, end_str);
	//ft_exists_wskip(&str, end_str, "");
	//if (str != end_str)
	//	exit(EXIT_FAILURE); //It didnt finiush fully.
	nullify(cmd);
	return (cmd);
}

void	show_cmd_tree(t_cmd *cmd)
{
	/*
	t_execcmd *execcmd;
	t_pipecmd *pipecmd;
	t_redircmd *redircmd;

	printf("TYPE: %i \n", cmd->type);
	pipecmd = (t_pipecmd *)cmd;
	redircmd = (t_redircmd *) pipecmd->left;
	execcmd =	(t_execcmd *) redircmd->link;
	printf("PIPE LEFT (REDIR LINK - CMD): %s", execcmd->argv[0]);
	execcmd = (t_execcmd *) pipecmd->right;
	printf("PIPE RIGHT (EXECCMD): %s\n", execcmd->argv[0]);
	*/
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

/* Recives 
	"ls -la | wc -l > hi"
	1. Start and End Address
	2. Send it to parse - gets back cmd.
*/

void	run_cmd(char *str)
{
	t_cmd	*cmd;	
	char	*end_str;

	printf("'%s'\n", str);	
	printf("Start STR: %p\n\n", str);
	end_str = str + ft_strlen(str);
	cmd = parsecmd(str, end_str);
	printf("\n\nEND STR: %p\n", end_str);
	printf("\n\n\n\n\n");

	show_cmd_tree(cmd);
}