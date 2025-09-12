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

int	ft_atoi(char *str)
{
	int	total;
	int	sign;

	sign = 1;
	total = 0;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str)
	{
		total *= 10;
		total += *str - '0'; 
		str++;
	}
	return (total * sign);
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