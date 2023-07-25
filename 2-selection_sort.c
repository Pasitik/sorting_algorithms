#include "sort.h"
#include <stdio.h>

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
	size_t i = 0, j, temp, min_value = 0;

	if (size < 2 || array == NULL)
		return;

	while (i < size - 1)
	{
		min_value = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[min_value])
			{
			min_value = j;
			}
			j++;
		}
		if (min_value != i)
		{
			temp = array[i];
			array[i] = array[min_value];
			array[min_value] = temp;
			print_array(array, size);
		}
		i++;
	}
}

