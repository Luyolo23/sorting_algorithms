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
 * createMaxHeap - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */
void createMaxHeap(int *array, size_t size, size_t base, size_t root)
{
	size_t lft, ryt, lrg;

	lft = 2 * root + 1;
	ryt = 2 * root + 2;
	lrg = root;

	if (lft < base && array[lft] > array[lrg])
		lrg = lft;
	if (ryt < base && array[ryt] > array[lrg])
		lrg = ryt;

	if (lrg != root)
	{
		swapInts(array + root, array + lrg);
		print_array(array, size);
		createMaxHeap(array, size, base, lrg);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */
void heap_sort(int *array, size_t size)
{
	int x;

	if (array == NULL || size < 2)
		return;

	for (x = (size / 2) - 1; x >= 0; x--)
		createMaxHeap(array, size, size, x);

	for (x = size - 1; x > 0; x--)
	{
		swapInts(array, array + x);
		print_array(array, size);
		createMaxHeap(array, size, x, 0);
	}
}
