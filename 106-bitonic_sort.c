#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bitonic_compare - comparess an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * @dir: direction to move
 */
void bitonic_compare(int *array, size_t size, int dir)
{
	size_t dist = size / 2;
	size_t i;
	int temp;

	for (i = 0; i < dist; i++)
	{
		if ((array[i] > array[i + dist]) == dir)
		{
			temp = array[i];
			array[i] = array[i + dist];
			array[i + dist] = temp;
		}
	}
}

/**
 * bitonic_merge - comparess an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * @dir: direction to move
 */
void bitonic_merge(int *array, size_t size, int dir)
{
	size_t dist;

	if (size <= 1)
		return;

	dist = size / 2;

	bitonic_compare(array, size, dir);
	bitonic_merge(array, dist, dir);
	bitonic_merge(array + dist, dist, dir);
}

/**
 * bitonic_sort_dir - comparess an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * @dir: direction
 */
void bitonic_sort_dir(int *array, size_t size, int dir)
{
	size_t dist;

	if (array == NULL || size <= 1)
		return;

	dist = size / 2;

	printf("Merging [%lu/16] (%s):\n", size, dir == 1 ? "UP" : "DOWN");
	print_array(array, size);
	/* Sort the first half in the given direction */
	bitonic_sort_dir(array, dist, 1);

	/* Sort the second half in the opposite direction i */
	bitonic_sort_dir(array + dist, dist, 0);

	/* Merge both halves in the specified direction */
	bitonic_merge(array, size, dir);
	printf("Result [%lu/16] (%s):\n", size, dir == 1 ? "UP" : "DOWN");
	print_array(array, size);
}

/**
 * bitonic_sort - comparess an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 *
 */

void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_dir(array, size, 1);
}
