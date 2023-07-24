#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers
 * using the bubble sort algorithm
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i;
	int temp, swapped = 1;

	if (size < 2 || array == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
	}
}

