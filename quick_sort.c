#include <stdio.h>

int partition(int *ar, int start, int end);
void  quick_sort(int *ar, int start, int end)
{
  if (end <= start)
    return;
  int pivot = partition(ar, start, end);
  quick_sort(ar, start, pivot - 1);
  quick_sort(ar, pivot + 1, end);
}

int partition(int *ar, int start, int end)
{
  int temp;
  int pivot = ar[end];

  int i = start - 1;

  for(int j = start; j <= end - 1; j++)
  {
    if (ar[j] < pivot)
    {
      i++;
      temp = ar[j];
      ar[j] = ar[i];
      ar[i] = temp;
    }
  }
  i++;
  temp = ar[i];
  ar[i] = ar[end];
  ar[end] = temp;
  return i;
}
int main()
{
  int array[] = {5, 4, 1, 9, 8};
  quick_sort(array, 0, 4);
  for (int i = 0; i <= 4; i++)
  {
    printf("%i ", array[i]);
  }
}
