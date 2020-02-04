#include "sort.h"
/**
 * shell_sort - shell sort method
 * @array: pointer to an array
 * @size:  size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int Tmp;

	if (array == NULL || size <= 1)
		return;
	while (gap < size)
		gap = gap * 3 + 1;
	gap = (gap - 1) / 3;
	while (gap > 0)
	{
		i = gap;
		while (i < size)
		{
			Tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > Tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = Tmp;
			i++;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}