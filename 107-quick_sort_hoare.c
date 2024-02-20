#include "sort.h"

/**
 * swapInts - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swapInts(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * hoareP - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @lft: The starting index of the subset to order.
 * @ryt: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */
int hoareP(int *array, size_t size, int lft, int ryt)
{
	int pivot, over, under;

	pivot = array[right];
	for (over = left - 1, under = right + 1; over < under;)
	{
		do {
			over++;
		} while (array[over] < pivot);
		do {
			under--;
		} while (array[under] > pivot);

		if (over < under)
		{
			swapInts(array + over, array + under);
			print_array(array, size);
		}
	}

	return (over);
}

/**
 * hoareSort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @lft: The starting index of the array partition to order.
 * @ryt: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoareSort(int *array, size_t size, int lft, int ryt)
{
	int p;

	if (ryt - lft > 0)
	{
		p = hoareP(array, size, lft, ryt);
		hoareSort(array, size, lft, p - 1);
		hoareSort(array, size, p, ryt);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoareSort(array, size, 0, size - 1);
}
