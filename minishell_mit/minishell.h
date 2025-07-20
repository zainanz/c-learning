/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:41:51 by zali              #+#    #+#             */
/*   Updated: 2025/07/20 15:44:15 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H 
# define MAX_SIZE 15

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>

enum {
	PIPE,
	EXEC,
	REDIR
};

typedef	struct execcmd
{
	int		type;
	char	*argv[MAX_SIZE];
	char	*eargv[MAX_SIZE];
}	t_execcmd;


typedef struct cmd
{
	int	type;
}	t_cmd;

typedef struct pipecmd
{
	int		type;
	t_cmd	*right;
	t_cmd	*left;
}	t_pipecmd;

typedef struct redircmd
{
	int		type;
	t_cmd	*link;
	char	*file;
	char	*end_file;
	int		mode;
	int		fd;
	char	redir_type;
}	t_redircmd;

// Execution
void	exec_tree(t_cmd *cmd, char **envp);

int		ft_putstr_fd(int fd, char *str);
char    *ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char *str);
int		safe_fork(void);
void	run_cmd(char *str, char **envp);
char	*ft_strcpy(char *dest, char *src);
void	*safe_malloc(int size);


#endif
