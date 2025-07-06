#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
typedef struct token
{
	char 	**cmd;
	int		pipe_in;
	int		pipe_out;
	char	*file_in;
	char	*file_out;
	int		is_append;
	int		is_heredoc;
}	t_token;

typedef struct tokens
{
	t_token	**tokens;
	int		size;
}	t_tokens;

#endif