#include "sort.h"
#include <stdio.h>

void merge(int *array, int *buff, size_t top, size_t mid, size_t down);
void merge_sort_recursive(int *array, int *buff, size_t top, size_t down);
void merge_sort(int *array, size_t size);

/**
 * merge_sort - Sort an array of integers
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	if (array == NULL || size < 2)
		return;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_recursive(array, buffer, 0, size);

	free(buffer);
}

/**
 * merge - Sort a subarray of integers.
 * @array: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @top: The front index of the array.
 * @mid: The middle index of the array.
 * @down: The back index of the array.
 */
void merge(int *array, int *buff, size_t top, size_t mid,
		  size_t down)
{
	size_t x, z, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + top, mid - top);

	printf("[right]: ");
	print_array(array + mid, down - mid);

	for (x = top, z = mid; x < mid && z < down; k++)
		buff[k] = (array[x] < array[z]) ? array[x++] : array[z++];
	for (; x < mid; x++)
		buff[k++] = array[x];
	for (; z < down; z++)
		buff[k++] = array[z];
	for (x = top, k = 0; x < down; x++)
		array[x] = buff[k++];

	printf("[Done]: ");
	print_array(array + top, down - top);
}

/**
 * merge_sort_recursive - Implement the merge sort algorithm
 * through recursion.
 * @array: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @top: The front index of the subarray.
 * @down: The back index of the subarray.
 */
void merge_sort_recursive(int *array, int *buff, size_t top, size_t down)
{
	size_t mid;

	if (down - top > 1)
	{
		mid = top + (down - top) / 2;
		merge_sort_recursive(array, buff, top, mid);
		merge_sort_recursive(array, buff, mid, down);
		merge(array, buff, top, mid, down);
	}
}
