#include "sort.h"

/**
 * max_heapify - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @n: The size of the array/tree.
 * @b: The index of the base row of the tree.
 * @i: The root node of the binary tree.
 */
void max_heapify(int *array, size_t n, size_t b, size_t i)
{
	int temp = 0;
	size_t largest  = i;
	size_t left = (2 * i) + 1;
	size_t right = (2 * i) + 2;

	if (left < b && array[left] > array[largest])
		largest = left;
	if (right < b && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		temp = array[largest];
		array[largest] = array[i];
		array[i] = temp;
		print_array(array, n);
		max_heapify(array, n, b, largest);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int i = 0, temp = 0;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
	{
		max_heapify(array, size, size, i);
		print_array(array, size);
	}

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);

		max_heapify(array, size, i, 0);
	}
}
