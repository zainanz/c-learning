/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zali <zali@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 18:26:11 by zali              #+#    #+#             */
/*   Updated: 2025/03/19 16:26:45 by zali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_extract_buffer_size(int fd, char *buffer)
{
	int	read_bytes;
	char	*t_buff;
	char	*prev;

	prev = NULL;
	read_bytes = 1;
	t_buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!t_buff)
		return (NULL);
	while (!ft_strchr(t_buff, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, t_buff, BUFFER_SIZE);
		if (read_bytes > 0)
		{
			t_buff[read_bytes] = '\0';
			prev = buffer;
			buffer = ft_strjoin(buffer, t_buff);
			free(prev);
		}
	}
	if (read_bytes == -1)
	{
		free(buffer);
		return (NULL);
	}
	free(t_buff);
	return (buffer);
}

char	*ft_extract_new_line(char *buffer)
{
	char	*ptr;
	size_t	len;
	char	*str;
	size_t	i;

	i = 0;
	ptr = ft_strchr(buffer, '\n');
	if (!ptr)
		return (NULL);
	printf("BUFFER: %p\n", buffer);
	printf("PTR: %p\n", ptr);
	len = (ptr - buffer) + 1;
	printf("Len: %li\n", len);
	str = malloc((len + 1) * sizeof(char));
	while (len > i++)
		str[i - 1] = buffer[i - 1];
	str[i] = '\0';
	printf("BUFFER: %s\n", buffer);
	printf("STR: %s\n", str);
	return (str);
}

char	*ft_skip_new_line(char *buffer)
{
	char	*ptr;
	int	new_buff_size;
	char	*new_buff;
	int	start;
	int	i;

	i = 0;
	ptr = ft_strchr(buffer, '\n');
	if (!ptr)
		return (buffer);
	new_buff_size = (ft_strlen(buffer) - ((ptr - buffer) + 1)) + 1;
	new_buff = malloc(sizeof(char) * (new_buff_size));
	start = ((ptr - buffer) + 1);
	while (i < new_buff_size)
	{
		new_buff[i] = buffer[start + i];
		i++;
	}
	new_buff[i] = '\0';
	free(buffer);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char	*line;

	line = NULL;
	buffer = ft_extract_buffer_size(fd, buffer);
	line = ft_extract_new_line(buffer);
	buffer = ft_skip_new_line(buffer);
	printf("LAST BUFFER: %s\n", buffer);
	return (line);
}


int	main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	char *buffer = get_next_line(fd);
	printf("%s\n", buffer);
	buffer = get_next_line(fd);
	printf("%s\n", buffer);
	buffer = get_next_line(fd);
	if (!buffer)
	{
		printf("Buffer is null\n");
	}
	else
	{
		printf("%s\n", buffer);
	}
	close(fd);
}
