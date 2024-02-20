#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @data_size: The size of the array.
 *
 * Description: Knuth interval sequence.
 */
void shell_sort(int *array, size_t data_size)
{
	size_t interval, i, j;

	if (array == NULL || data_size < 2)
		return;

	for (interval = 1; interval < (data_size / 3);)
		interval = interval * 3 + 1;

	for (; interval >= 1; interval /= 3)
	{
		for (i = interval; i < data_size; i++)
		{
			j = i;
			while (j >= interval && array[j - interval] > array[j])
			{
				swap_ints(array + j, array + (j - interval));
				j -= interval;
			}
		}
		print_array(array, data_size);
	}
}
