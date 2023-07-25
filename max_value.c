#include "sort"

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
    for (int i = 0; i < size; i ++)
    {
        if (array[i] > k)
            k = array[i];
    }
    return k;
}
