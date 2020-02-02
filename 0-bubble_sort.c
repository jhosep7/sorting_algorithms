#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: Array
 * @size: size
 * Return: Void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = size - 1, j, Temp;
	bool k = true;

	if (!array || size <= 1)
	{return; }

	while (k)
	{
		k = false;
		for (j = 0; j < (size - 1); j++)
		{
			if (array[j] > array[j + 1])
			{
				Temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = Temp;
				k = true;
				print_array(array, size);
			}
		}
		i--;
	}
}
