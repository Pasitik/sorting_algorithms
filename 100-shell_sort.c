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
	size_t gap = 0, j = 0, temp = 0;

	for (gap = size/2; gap >= 1; gap/=2)
	{
		for (j = gap; j < size; j++)
		{
			for (i = j - gap; i >= 0; i -= gap)
			{
				if (array[i+gap] > array[i])
					break;
				else
				{
					temp = array[i + gap];
					array[i + gap] = array[i];
					array[i] = temp;
					print_array(array, size);
				}
			}
		}
	}
}
