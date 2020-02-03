#include "sort.h"

/**
 * quick_sort - sorts an array of ints in ascending order
 * @array: Array
 * @size: size
 * Return: Void
 */
void quick_sort(int *array, size_t size)
{
	int Init = 0, Final = size - 1;

	if (size == 0 || !array)
	{return; }
	Sort(array, Init, Final, size);
}

/**
 * Sort - sorts array by using Init and Final positions.
 * @array: Array
 * @Init: First Idx Array
 * @Final: Last Idx Array
 * @size: size
 * Return: Void
 */
void Sort(int *array, int Init, int Final, size_t size)
{
	int Pivot;

	if (Init < Final)
	{
		Pivot = Partition(array, Init, Final, size);
		Sort(array, Init, Pivot - 1, size);
		Sort(array, Pivot + 1, Final, size);
	}
}

/**
 * Partition - split array using Lomuto Algorithm
 * @array: Array
 * @Init: First Idx Array
 * @Final: Last Idx Array
 * @size: size
 * Return: Void
 */
int Partition(int *array, int Init, int Final, size_t size)
{
	int Pivot = array[Final], i = Init - 1, j, Temp;

	for (j = Init; j <= Final; j++)
	{
		if (array[j] <= Pivot)
		{
			i++;
			if (i != j)
			{
				Temp = array[i];
				array[i] = array[j];
				array[j] = Temp;
				print_array(array, size);
			}
		}
	}
	return (i);
}
