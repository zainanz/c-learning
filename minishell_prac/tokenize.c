/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:15:36 by zali              #+#    #+#             */
/*   Updated: 2025/07/07 12:46:40 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_words(char *prompt)
{
	int		i;
	int		words;
	char	quoted;

	words = 0;
	i = 0;
	quoted = 0;
	while (prompt[i])
	{
		while (prompt[i] == ' ')
			i++;
		if (prompt[i] == '\'' || prompt[i] == '"')
		{
			quoted = prompt[i++];
			while (prompt[i] != quoted)
				i++;
			words++;
			i++;
			continue ;
		}
		while (prompt[i]
				&& (prompt[i + 1] != ' ' && prompt[i + 1] != 0))
			i++;
		if ((prompt[i + 1] == ' ' || prompt[i + 1] == '\0')
			&& prompt[i])
			words++;
		if (prompt[i])
			i++;
	}
	return (words);
}

int	find_end(char *prompt, char c)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == c || prompt[i] == 0)
			return (i);
		i++;
	}
	return (i);
}

int	extract_str(char **str, char *prompt, int len)
{
	int	i;

	i = 0;
	*str = malloc(sizeof(char) * len + 1);
	if (!str)
	{
		perror("malloc erorr");
		exit(EXIT_FAILURE);
	}
	while (i < len)
	{
		(*str)[i] = prompt[i];
		i++;
	}
	(*str)[i] = 0;
	return (len);
}

static char	**ft_split_append(char **strs, int size, char *prompt)
{
	int	curr_end;
	int	index;

	curr_end = 0;
	// index = 0;
	while (*prompt)
	{
		while (*prompt == ' ')
			prompt++;
		if (*prompt == '\'' || *prompt == '"')
		{
			prompt++;
			curr_end = find_end(prompt, *(prompt - 1)); 
		}
		else
			curr_end = find_end(prompt, ' ');
		prompt += extract_str(&strs[index++], prompt, curr_end);
		if (*prompt)
			prompt++;
	}
}

char	**ft_split(char *prompt)
{
	int		total_words;
	char	**str_ar;

	total_words = count_words(prompt);
	str_ar = malloc(sizeof(char *) * (total_words + 1));
	if (!str_ar)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	str_ar[total_words] = 0;
	ft_split_append(str_ar, total_words, prompt);
	return (str_ar);
}

void	parse_prompt(char *str, t_token *token)
{
	printf("Parsing: %s\n", str);
}

static t_token	**tokenize(char **strs)
{
	t_tokens	*tokens_ar;
	t_token		*token;
	int			i;

	i = 0;
	tokens_ar->size = 1;
	tokens_ar->tokens = NULL;
	while (strs[i])
		while (strs[i][++j])
			if(strs[i][j] == '|')
			tokens_ar->size++;
	tokens_ar->tokens = malloc(sizeof(t_token) * tokens_ar->size);
	i = 0;
	while (i < tokens_ar->size)
	{
		parse_prompt(strs[i], tokens_ar->tokens[i]);
		free(strs[i]);
	}
}

char **tokenize_prompt(char *prompt)
{
	char	**strs;

	strs = ft_split(prompt);
	tokenize(strs);
}

void	display_strs(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%i. >%s<\n", i, str[i]);
		i++;
	}
}

int main(void)
{
	char **strs = tokenize_prompt("ls -l | wc -l > filename");
	display_strs(strs);
}