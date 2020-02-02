#include "sort.h"

/**
 * selection_sort -  sorts an array of integers in ascending orde
 * @array: Array
 * @size: size
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t Aux, i = 0, j, Lowest_Idx;

	if (!array)
	{return; }
	for (i = 0; i < size - 1; i++)
	{
		Lowest_Idx = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[Lowest_Idx])
			{Lowest_Idx = j; }
			j++;
		}
		if (Lowest_Idx == i)
		{continue; }
		Aux = array[Lowest_Idx];
		array[Lowest_Idx] = array[i];
		array[i] = Aux;
		print_array(array, size);
	}
}
