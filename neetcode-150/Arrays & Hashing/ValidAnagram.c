int	is_present(char c, char *t)
{
	while (*t)
		if (c == *t++)
			return (1);
	return (0);
}

int	total_equal_letters(char *s, char *t, char c)
{
	int	total_s;
	int	total_t;

	total_s = 0;
	total_t = 0;
	if (!s || !t)
		return (0);
	while (*s)
		if (*s++ == c)
			total_s++;
	while (*t)
		if (*t++ == c)
			total_t++;
	return (total_s == total_t);
}

int isAnagram(char *s, char *t)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!is_present(s[i], t))
			return (0);
		if (!total_equal_letters(s, t, s[i]))
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>

int main(void)
{
	char *first = "racecarrasdasd";
	char *second = "carraceasdasdr";
	printf("%i\n", isAnagram(first, second));
}
*/
