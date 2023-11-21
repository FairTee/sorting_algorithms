#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void merge_sort_recursive(int *array, size_t low, size_t high, int *temp);
void merge(int *array, size_t low, size_t mid, size_t high, int *temp);
/**
 * merge_sort - Sorts an array of integers using
 * the Merge sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	/* Allocate a temporary array for merging */
	temp = malloc(size * sizeof(int));

	if (temp == NULL)
		return;

	/* Call the recursive merge sort function */
	merge_sort_recursive(array, 0, size - 1, temp);

	/* Free the temporary array */
	free(temp);
}

/**
 * merge_sort_recursive - Recursive function for Merge sort
 * @array: Array to be sorted
 * @low: Starting index of the sub-array
 * @high: Ending index of the sub-array
 * @temp: Temporary array for merging
 */
void merge_sort_recursive(int *array, size_t low, size_t high, int *temp)
{
	if (low < high)
	{
		/* Find the middle point */
		size_t mid = low + (high - low) / 2;

		/* Recursively sort the left and right sub-arrays */
		merge_sort_recursive(array, low, mid, temp);
		merge_sort_recursive(array, mid + 1, high, temp);

		/* Merge the sorted sub-arrays */
		merge(array, low, mid, high, temp);
	}
}

/**
 * merge - Merges two sub-arrays into a sorted array
 * @array: Array to be sorted
 * @low: Starting index of the first sub-array
 * @mid: Ending index of the first sub-array
 * @high: Ending index of the second sub-array
 * @temp: Temporary array for merging
 */
void merge(int *array, size_t low, size_t mid, size_t high, int *temp)
{
	size_t i = low, j = mid + 1, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + low, mid - low + 1);
	printf("[right]: ");
	print_array(array + mid + 1, high - mid);

	while (i <= mid && j <= high)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i <= mid)
		temp[k++] = array[i++];

	while (j <= high)
		temp[k++] = array[j++];

	for (i = 0; i < k; i++)
		array[low + i] = temp[i];

	printf("[Done]: ");
	print_array(array + low, high - low + 1);
}
