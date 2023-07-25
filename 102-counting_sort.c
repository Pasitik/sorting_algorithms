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

	for (i = 0; i < size; i ++)
	{
		if (array[i] > k)
			k = array[i];
	}
	return k;
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int k = max(array, size);
	int *count, *temp, i = 0;


	temp = malloc (sizeof(int) * size);
	count = malloc (sizeof(int) * (k + 1));

	for (i = 0; i <= k; i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		++count[array[i]];
	for (i = 0; i <=k; i++)
		count[i] = count[i] + count[i - 1];
	print_array(count, k+1);
	for (i = size - 1; i >= 0; i--)
		temp[--count[array[i]]] = array[i];
	for (i = 0; i < (int)size; i++)
		array[i] = temp[i];

	free(count);
	free(temp);
}

