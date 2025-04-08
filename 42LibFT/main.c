#include "libft.h"
#include <stdio.h>
int	main(void)
{
	char *name;
	
	name = malloc(sizeof(char) * 6);
	ft_memset((void *)name, 'z', 6);
	printf("%s", name);
}
