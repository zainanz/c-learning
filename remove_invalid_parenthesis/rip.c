#include <stdio.h>

void	calc_prans(char *str, char *c, int *val)
{
	int left;
	int right;
	left = 0;
	right = 0;
	while (*str)
	{
		if (*str == '(')
			left++;
		if (*str == ')')
			right++;
		str++;
	}
	if (left == right)
	{
		*val = 0;
		*c = ' ';
	}
	if (left > right)
	{
		*val = left - right;
		*c = '(';
	}
	else
	{
		*val = right - left;
		*c = ')';
	}
}

int	check_balanced(char *str)
{
	int i;
	int j;
	int last_j;

	i = 0;
	j = 0;
	last_j = -1;
	while (str[i])
	{
		if (str[i] == '(')
		{
			j = i;
			while (str[j] && str[j] != ')')
			{
				j++;	
				if (last_j == -1)
					last_j = j;
				else
				{
					if (last_j == j)
						j++;
				}
			}
			if (!str[j])
				return (0);
			last_j = j;
		}
		i++;
	}
	return (1);
}

void	rip(char *str, int str_len, int index)
{
	char	c;
	int	unbalanced;
	(void) index;
	int i;
	// printf("enters rip\n");
	calc_prans(str, &c, &unbalanced);
	if (unbalanced == 0)
	{
		if (check_balanced(str))
			printf("%s\n", str);
		return ;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			str[i] = ' ';
			rip(str, str_len, index);
			str[i] = c;
		}
		i++;
	}
}

int	main(void)
{
	char str[] = "(()))))()()))";
	rip(str, 6, 0);
}