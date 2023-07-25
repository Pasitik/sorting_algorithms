#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the selection sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_value, temp;

	for (i = 0; i < size; i++)
	{
		min_value = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min_value] > array[j])
				min_value = j;
		}

		if (min_value != i)
		{
			temp = array[i];
			array[i] = array[min_value];
			array[min_value] = temp;
			print_array(array, size);
		}
	}
}

