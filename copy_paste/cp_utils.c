#include "copy_paste.h"
#include <fcntl.h>

int	ft_putstr_fd(int fd, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i);
	return (i);
}

static int	open_file(char *filename, int FLAG)
{
	int	fd;
	fd = open(filename, FLAG);
	if (fd == -1)
	{
		ft_putstr_fd(2, filename);
		ft_putstr_fd(2, " does not exist.\n");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

static int	get_file_bytes(char *file_name)
{
	char	buff[BUFFER_SIZE];
	int		read_bytes;
	int		fd;
	int		total_read;

	read_bytes = 1;
	total_read = 0;
	fd = open_file(file_name, O_RDONLY);
	while (read_bytes)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		total_read += read_bytes;
	}
	close(fd);
	return (total_read);
}

static void	copy_to_file(char *content, int content_size, char *file_name, char *file_to_create)
{
	int	fd;
	int	write_fd;

	fd = open_file(file_name, O_RDONLY);
	if (read(fd, content, content_size) == -1)
	{
		perror("read error");
		exit(EXIT_FAILURE);
	}
	write_fd = open_file(file_to_create, O_WRONLY | O_CREAT);
	if (write(write_fd, content, content_size) == -1)
	{
		perror("write error");
		exit(EXIT_FAILURE);
	}
	close(write_fd);
	close(fd);
}

int	make_copy(char *cp_file, char *file_to_create)
{
	int		total_bytes;
	char	*content;

	total_bytes = get_file_bytes(cp_file);
	content = malloc(sizeof(char) * total_bytes);
	if (!content)
	{
		ft_putstr_fd(2, "Malloc error.\n");
		exit(EXIT_FAILURE);
	}
	copy_to_file(content, total_bytes, cp_file, file_to_create);	
	free(content);
	return (1);
}
