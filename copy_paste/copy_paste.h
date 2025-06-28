#ifndef COPY_PASTE_H
# define COPY_PASTE_H
# define BUFFER_SIZE 4096
# include <unistd.h> // write
# include <fcntl.h> // open - access
# include <stdlib.h> // exit_success - exit_failure
# include <stdio.h> // scanf 

int	ft_putstr_fd(int fd, char *str);
int	make_copy(char *cp_file, char *file_to_create);
#endif
