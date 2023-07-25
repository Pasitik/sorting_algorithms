#include "sort.h"

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	int i = 0;
	size_t gap = 1, j = 0, temp = 0;

	while (gap <= size / 3)
	{
		gap = gap * 3 + 1;
	}

	while (gap > 0)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (array[i + gap] >= array[i])
					break;

				temp = array[i + gap];
				array[i + gap] = array[i];
				array[i] = temp;
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}

