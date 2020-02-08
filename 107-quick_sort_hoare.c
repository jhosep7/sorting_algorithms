#include "sort.h"

/**
 * quick_sort_hoare - sorts an array Hoare
 * @array: Array
 * @size: size
 * Return: Void
 */
void quick_sort_hoare(int *array, size_t size)
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
		Sort(array, Init, Pivot, size);
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
	int Pivot = array[Final], i = Init - 1, j = Final + 1, Temp;

	while (true)
	{
		do
		{
			i++;
		}while (array[i] < Pivot);

		do
		{
			j--;
		}while (array[j] > Pivot);

		if (i > j)
		{return (j); }
		if (i == j)
		{return (j - 1); }
		Temp = array[i];
		array[i] = array[j];
		array[j] = Temp;
		print_array(array, size);
	}
}
