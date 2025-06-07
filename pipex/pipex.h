/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:02:05 by zali              #+#    #+#             */
/*   Updated: 2025/06/07 18:56:02 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

// String utils
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char const *s1, char const *s2);

// Pipex Utils
void	close_files(int *fd, int *pipefd);
void	pid2_exec(int *fd, int *pipefd, char *cmd);
void	pid1_exec(int *fd, int *pipefd, char *cmd);
void	run_process(char *str);
void	open_files(int *fd, char *argv[]);

#endif
