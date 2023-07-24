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

void bubble_sort(int *myarray, size_t size)
{
	size_t  idx, i;
	int temp;
	
	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (idx = 0; idx < size - i - 1; idx++)
		{
			if (myarray[idx] > myarray[idx + 1])
			{
				temp = myarray[idx];
				myarray[idx] = myarray[idx + 1];
				myarray[idx + 1] = temp;
				print_array(myarray, size);
			}
		}
	}
}

