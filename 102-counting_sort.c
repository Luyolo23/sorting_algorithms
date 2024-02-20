#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max_value, x;

	for (max_value = array[0], x = 1; x < size; x++)
	{
		if (array[x] > max_value)
			max_value = array[x];
	}

	return (max_value);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sorted, max_value, x;

	if (array == NULL || size < 2)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	max_value = get_max(array, size);
	count = malloc(sizeof(int) * (max_value + 1));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (x = 0; x < (max_value + 1); x++)
		count[x] = 0;
	for (x = 0; x < (int)size; x++)
		count[array[x]] += 1;
	for (x = 0; x < (max_value + 1); x++)
		count[x] += count[x - 1];
	print_array(count, max_value + 1);

	for (x = 0; x < (int)size; x++)
	{
		sorted[count[array[x]] - 1] = array[x];
		count[array[x]] -= 1;
	}

	for (x = 0; x < (int)size; x++)
		array[x] = sorted[x];

	free(sorted);
	free(count);
}
