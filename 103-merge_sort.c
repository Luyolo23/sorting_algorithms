#include "sort.h"

/**
 * mergeSubarrays - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @leftIndex: The front index of the array.
 * @middleIndex: The middle index of the array.
 * @rightIndex: The back index of the array.
 */
void mergeSubarrays(int *subarr, int *buff, size_t leftIndex,
		size_t middleIndex, size_t rightIndex)
{
	size_t x, y, z = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + leftIndex, middleIndex - leftIndex);

	printf("[right]: ");
	print_array(subarr + middleIndex, rightIndex - middleIndex);

	for (x = leftIndex, y = middleIndex; x < middleIndex && y < rightIndex; z++)
		buff[z] = (subarr[x] < subarr[y]) ? subarr[x++] : subarr[y++];
	for (; x < middleIndex; x++)
		buff[z++] = subarr[x];
	for (; y < rightIndex; y++)
		buff[z++] = subarr[y];
	for (x = leftIndex, z = 0; x < rightIndex; x++)
		subarr[x] = buff[z++];

	printf("[Done]: ");
	print_array(subarr + leftIndex, rightIndex - leftIndex);
}

/**
 * mergeSortRecursive - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @leftIndex: The front index of the subarray.
 * @rightIndex: The back index of the subarray.
 */
void mergeSortRecursive(int *subarr, int *buff,
		size_t leftIndex, size_t rightIndex)
{
	size_t middleIndex;

	if (rightIndex - leftIndex > 1)
	{
		middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
		mergeSortRecursive(subarr, buff, leftIndex, middleIndex);
		mergeSortRecursive(subarr, buff, middleIndex, rightIndex);
		mergeSubarrays(subarr, buff, leftIndex, middleIndex, rightIndex);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	mergeSortRecursive(array, buff, 0, size);

	free(buff);
}
