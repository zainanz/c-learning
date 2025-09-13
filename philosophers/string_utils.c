#include "philo.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

size_t	get_current_time(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	get_valid_num(char *str)
{
	size_t	total;

	if (!str)
		return (0);
	total = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			ft_putstr_fd("\033[31m[ERROR]\033[0m only positive int range is accepted.\n", 2);
			exit(EXIT_FAILURE);
		}
		total *= 10;
		total += *str - '0'; 
		if (total > INT_MAX)
		{
			ft_putstr_fd("\033[31m[ERROR]\033[0m only positive int range is accepted.\n", 2);
			exit(EXIT_FAILURE);
		}
		str++;
	}
	return (total);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}