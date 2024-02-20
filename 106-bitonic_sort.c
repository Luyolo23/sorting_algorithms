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
 * bitonicMerge - Sort a bitonic sequence inside an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @sequence: The size of the sequence to sort.
 * @flow: The direction to sort in.
 */
void bitonicMerge(int *array, size_t size, size_t start,
		size_t sequence, char flow)
{
	size_t x, hop = sequence / 2;

	if (sequence > 1)
	{
		for (x = start; x < start + hop; x++)
		{
			if ((flow == UP && array[x] > array[x + hop]) ||
			    (flow == DOWN && array[x] < array[x + hop]))
				swapInts(array + x, array + x + hop);
		}
		bitonicMerge(array, size, start, hop, flow);
		bitonicMerge(array, size, start + hop, hop, flow);
	}
}

/**
 * bitonicSequence - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @sequence: The size of a block of the building bitonic sequence.
 * @flow: Direction to sort the bitonic sequence block in.
 */
void bitonicSequence(int *array, size_t size, size_t start,
		size_t sequence, char flow)
{
	size_t cut = sequence / 2;
	char *str = (flow == UP) ? "UP" : "DOWN";

	if (sequence > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sequence, size, str);
		print_array(array + start, sequence);

		bitonicSequence(array, size, start, cut, UP);
		bitonicSequence(array, size, start + cut, cut, DOWN);
		bitonicMerge(array, size, start, sequence, flow);

		printf("Result [%lu/%lu] (%s):\n", sequence, size, str);
		print_array(array + start, sequence);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending
 *                order using the bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each swap. Only works for
 * size = 2^k where k >= 0 (ie. size equal to powers of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_seq(array, size, 0, size, UP);
}
