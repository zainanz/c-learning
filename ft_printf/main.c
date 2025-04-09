#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	ft_printf("- %i\n", ft_printf(" %-13p %p ", ULONG_MAX, -ULONG_MAX));
	printf("- %i\n", printf(" %-13p %p ", ULONG_MAX, -ULONG_MAX));
}
