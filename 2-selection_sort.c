#include "sort.h"

/**
 * selection_sort -  sorts an array of integers in ascending orde
 * @array: Array
 * @size: size
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t Temp, i, j, Min_Idx;

	if (!array || size <= 1)
	{return; }
	i = 0;
	while (i < (size - 1))
	{
		Min_Idx = i;
		j = (i + 1);
		while (j < size)
		{
			if (array[j] < array[Min_Idx])
			{Min_Idx = j; }
			j++;
		}
		Temp = array[Min_Idx];
		array[Min_Idx] = array[i];
		array[i] = Temp;
		print_array(array, size);
		i++;
	}
}
