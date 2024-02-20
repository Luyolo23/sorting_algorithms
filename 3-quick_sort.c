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
 * lomuto_p - Order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: The array of integers.
 * @data_size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 */
int lomuto_p(int *array, size_t data_size, int left, int right)
{
	int *pivot, over, under;

	pivot = array + right;
	for (over = under = left; under < right; under++)
	{
		if (array[under] < *pivot)
		{
			if (over < under)
			{
				swap_ints(array + under, array + over);
				print_array(array, data_size);
			}
			over++;
		}
	}

	if (array[over] > *pivot)
	{
		swap_ints(array + over, pivot);
		print_array(array, data_size);
	}

	return (over);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @data_size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t data_size, int left, int right)
{
	int pivotIndex;

	if (right - left > 0)
	{
		part = lomuto_p(array, data_size, left, right);
		lomuto_sort(array, data_size, left, pivotIndex - 1);
		lomuto_sort(array, data_size, pivotIndex + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @data_size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t data_size)
{
	if (array == NULL || data_size < 2)
		return;

	lomuto_sort(array, data_size, 0, data_size - 1);
}
