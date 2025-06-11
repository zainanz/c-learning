#include <stdio.h>
typedef int bool;
enum {
	false,
	true
};
bool ContainsDuplicate(int *nums, int numsSize)
{
	for (int i = 0; i < numsSize; i++)
	{
		for (int j = 0; j < numsSize; j++)
			if (nums[i] == nums[j] && i != j)
				return (true);
	}
	return (false);
}
int	main(void)
{
	int nums[] = {5, 1203, 23, 103, 103};
	printf("%i\n", ContainsDuplicate(nums, 5));
}
/*
 Note 
 - > The better approach would be to use a hash table
	for each_item in nums
		if (exists in hashtable (i.e value is 1 already))
			return (true);
		hash[nums] = 1;
	return (false);
	C doesnt have a built in hash table so you have to make one yourself.
*/
