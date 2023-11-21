#include "sort.h"

/**
 * max_value - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: Maximum integer in the array.
 */
int max_value(int *array, int size)
{
	int maxim, x;

	for (maxim = array[0], x = 1; x < size; x++)
	{
		if (array[x] > maxim)
			maxim = array[x];
	}

	return (maxim);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sort, maxim, x;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;
	maxim = max_value(array, size);
	count = malloc(sizeof(int) * (maxim + 1));
	if (count == NULL)
	{
		free(sort);
		return;
	}

	for (x = 0; x < (maxim + 1); x++)
		count[x] = 0;
	for (x = 0; x < (int)size; x++)
		count[array[x]] += 1;
	for (x = 0; x < (maxim + 1); x++)
		count[x] += count[x - 1];
	print_array(count, maxim + 1);

	for (x = 0; x < (int)size; x++)
	{
		sort[count[array[x]] - 1] = array[x];
		count[array[x]] -= 1;
	}

	for (x = 0; x < (int)size; x++)
		array[x] = sort[x];

	free(sort);
	free(count);
}
