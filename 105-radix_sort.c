#include "sort.h"
/**
 * radix_sort - Sorting by radix form
 * @array: pointer to an array
 * @size: size of array
 */
void radix_sort(int *array, size_t size)
{
  int may = Maximo(array, size);

  for (int exp = 1; may/exp > 0; exp *= 10)
  {conteo(array, size, exp); }
}

/**
 * Maximo - Gets max value of array
 * @arr: array
 * @n: size of array
 * Return: max value
 */
int Maximo(int arr[], int n)
{
    int maximo = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maximo)
        {maximo = arr[i]; }
    return maximo;
}

/**
 * conteo - Sorting
 * @arr: array
 * @n: size of array
 * @exp: exp
 */

void conteo(int arr[], int n, int exp)
{
    int arrB[n];
    int i, cuenta[10] = {0};

    for (i = 0; i < n; i++)
    {cuenta[ (arr[i]/exp)%10 ]++; }

    for (i = 1; i < 10; i++)
    {cuenta[i] += cuenta[i - 1]; }

    for (i = n - 1; i >= 0; i--)
    {
        arrB[cuenta[ (arr[i]/exp)%10 ] - 1] = arr[i];
        cuenta[ (arr[i]/exp)%10 ]--;
    }

    for (i = 0; i < n; i++)
    {arr[i] = arrB[i]; }
    print_array(arr, n);
}
