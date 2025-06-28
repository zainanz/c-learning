#include "copy_paste.h"

int	file_already_exists(char *file_to_create)
{
	if (access(file_to_create, F_OK) == 0)
		return (1);
	return (0);
}
void	ask_to_overwrite(char *file)
{
	char	c;

	ft_putstr_fd(1, file);
	ft_putstr_fd(1, " already exists. would you like to overwrite?\n (Y/N): ");
	scanf(" %c", &c);
	if (c != 'y' || c != 'Y')
		exit (EXIT_FAILURE);
	else
		return ;
}


int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		ft_putstr_fd(2, "Usage: ./cp 'file to copy' 'location'\n");
		return (EXIT_FAILURE);
	}
	if (file_already_exists(argv[2]))
		ask_to_overwrite(argv[2]);
	make_copy(argv[1], argv[2]);
	return (EXIT_SUCCESS);
}
