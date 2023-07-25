#include "sort.h"

/**
 * max - finds the max value in an array
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: maximum value
 */
int max(int *array, size_t size)
{
	int k = 0;
	size_t i = 0;

	for (i = 0; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	return (k);
}

/**
 * count_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @pos: The position of the item.
 * @temp: The temporary Array.
 */
void count_sort(int *array, size_t size, int pos, int *temp)
{
	int k = 9, j = 0;
	int count[10] = {0};
	size_t i = 0;


	for (i = 0; i < size; i++)
	{
		++count[(array[i] / pos) % 10];
	}

	for (j = 1; j <= k; j++)
	{
		count[j] = count[j] + count[j - 1];
	}

	for (j = size - 1; j >= 0; j--)
	{
		temp[--count[((array[j] / pos) % 10)]] = array[j];
	}

	for (i = 0; i < size; i++)
	{
		array[i] = temp[i];
	}

}



/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
	int pos = 0;
	int *temp;
	int max_val = max(array, size);

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
	{
		return;
	}

	for (pos = 1; max_val / pos > 0; pos *= 10)
	{
		count_sort(array, size, pos, temp);
		print_array(array, size);
	}
	free(temp);
}

