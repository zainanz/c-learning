/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:36:13 by zali              #+#    #+#             */
/*   Updated: 2025/07/20 17:19:28 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			cmd = init_t_redircmd(cmd, ptr, ptr_end, O_RDONLY, 0);
		else if (token == '-') // <<
			cmd = init_t_redircmd(cmd, ptr, ptr_end, O_RDONLY, 0);
		else if (token == '>') // >
			cmd = init_t_redircmd(cmd, ptr, ptr_end, O_WRONLY | O_TRUNC | O_CREAT, 1);
		else if (token == '+') // >>
			cmd = init_t_redircmd(cmd, ptr, ptr_end, O_WRONLY | O_CREAT, 1);
		((t_redircmd *)cmd)->redir_type = token;
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
	exec_cmd = (t_execcmd *) init_t_execcmd();
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