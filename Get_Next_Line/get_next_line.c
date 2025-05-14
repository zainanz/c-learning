/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:35:10 by zali              #+#    #+#             */
/*   Updated: 2025/05/11 14:09:00 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*trim_buffer(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new_buff;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	new_buff = malloc(ft_strlen(buffer + i) + 1);
	if (!new_buff)
		return (NULL);
	while (buffer[i])
		new_buff[j++] = buffer[i++];
	new_buff[j] = '\0';
	free(buffer);
	return (new_buff);
}

static char	*extract_line(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (!buffer || !*buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

static void	*free_return_null(char *ptr)
{
	free(ptr);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*read_buf;
	ssize_t		bytes_read;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buf)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_return_null(read_buf));
		read_buf[bytes_read] = '\0';
		buffer = ft_strjoin_and_free(buffer, read_buf);
	}
	free(read_buf);
	if (!buffer || !*buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = trim_buffer(buffer);
	return (line);
}
