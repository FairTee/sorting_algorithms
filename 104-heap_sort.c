#include "sort.h"

/**
 * swaps_root - swaps root node
 * @array: array
 * @root: root of heap
 * @high: main
 * @size: size
 * Return: 0
 */
void swaps_root(int *array, size_t root, size_t high, size_t size)
{
	size_t q = 0, n = 0, tmp = 0;
	int x = 0;

	while ((q = (2 * root + 1)) <= high)
	{
		tmp = root;
		n = q + 1;
		if (array[tmp] < array[q])
			tmp = q;
		if (n <= high && array[tmp] < array[n])
			tmp = n;
		if (tmp == root)
			return;
		x = array[root];
		array[root] = array[tmp];
		array[tmp] = x;
		print_array(array, size);
		root = tmp;
	}
}

/**
 * heap_sort - sorts using heap method
 * @array: array
 * @size: size
 * Return: 0
 */
void heap_sort(int *array, size_t size)
{
	size_t high = 0, x = 0;
	int tmp = 0;

	if (array == NULL || size < 2)
		return;
	for (x = (size - 2) / 2; 1; x--)
	{
		swaps_root(array, x, size - 1, size);
		if (x == 0)
			break;
	}
	high = size - 1;
	while (high > 0)
	{
		tmp = array[high];
		array[high] = array[0];
		array[0] = tmp;
		print_array(array, size);
		high--;
		swaps_root(array, 0, high, size);
	}
}
