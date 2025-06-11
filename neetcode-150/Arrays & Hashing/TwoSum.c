#include <stdio.h>
#include <stdlib.h>

int	*TwoSum(int *nums, int nums_size, int target)
{
	int	*ar;

	ar = malloc(sizeof(int) * 2);
	ar[0] = 0;
	ar[1] = 0;
	while (ar[0] < nums_size)
	{
		while (ar[1] < nums_size)
		{
			if (ar[1] != ar[0] && nums[ar[1]] + nums[ar[0]] == target)
				break ;
			ar[1]++;
		}
		ar[0]++;
	}
	return (ar);
}
int	main(void)
{
	int nums[] = {3,4,5,6};
	int *ar = TwoSum(nums, 4, 7);
	printf("%i, %i\n", ar[0], ar[1]);
}
