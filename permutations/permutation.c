#include <stdio.h> 
#include <string.h> 

/* Function to swap values at 
   two pointers */
void swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
} 

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void permutate(char *str, int index)
{
	int i = index;
	int str_size = ft_strlen(str);  
	if (str[i] && !str[i + 1])
	{
		printf("%s\n", str);
		return ;
	}
	while (str[i]) 
	{
		swap(str + index, str + i);
		permutate(str, index + 1);
		swap(str + index, str + i);
		i++;
	}
}
/* Function to print permutations 
   of string 
   This function takes three parameters: 
   1. String 
   2. Starting index of the string 
   3. Ending index of the string. */

void main(void)
{
	char str[] = "ABC"; 
	permutate(str, 0);
}