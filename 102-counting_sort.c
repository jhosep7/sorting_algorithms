#include "sort.h"

/**
 * counting_sort -  Counting sort
 * @array: Array
 * @size: Size
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	size_t Aux, Sum, i = 0;
	int *CountArr, *NewArr, higher, Num = 0;

	if (!array || size <= 1)
	{return; }
	NewArr = malloc(sizeof(*array) * size);
	if (!NewArr)
	{return; }
	while (i < size)
	{
		NewArr[i] = array[i];
		if (array[i] > higher)
		{ higher = array[i] + 1; }
		i++;
	}
	CountArr = malloc(sizeof(*CountArr) * higher);
	if (!CountArr)
	{
		free(NewArr);
		return;
	}
	for (i = 0; i < size; i++)
	{CountArr[array[i]]++; }
	Sum = 0;
	while (Num < higher)
	{
		Aux = CountArr[Num], CountArr[Num] += Sum;
		Sum += Aux, Num++;
	}
	print_array(CountArr, higher), i = 0;
	while (i < size)
	{
		array[CountArr[NewArr[i]] - 1] = NewArr[i];
		CountArr[NewArr[i]]--, i++;
	}
	free(CountArr),	free(NewArr);
}
