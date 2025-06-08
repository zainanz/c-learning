/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 17:16:35 by zali              #+#    #+#             */
/*   Updated: 2025/06/07 22:23:20 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[])
{
	int		fd[2];
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (argc != 5)
	{
		write(STDERR_FILENO, "Usage: ./pipex infile 'ls -l' 'wc -l' outfile.\n",
			47);
		exit(EXIT_FAILURE);
	}
	open_files(fd, argv);
	if (pipe(pipefd) < 0)
		exit(EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == 0)
		pid1_exec(fd, pipefd, argv[2]);
	pid2 = fork();
	if (pid2 == 0)
		pid2_exec(fd, pipefd, argv[3]);
	close_files(fd, pipefd);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	return ((status >> 8) & 0xFF);
}
