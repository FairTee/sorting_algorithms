#include "sort.h"

void swap_integer(int *a, int *b);
int hoare_partition(int *array, size_t size, int left, int right);
void hoare_sort(int *array, size_t size, int left, int right);

/**
 * swap_ints - Swap two integers in an array.
 * @x: The first integer to swap.
 * @y: The second integer to swap.
 */
void swap_integer(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * hoare_partition - Order a subset of an array of integers
 * according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, top, down;

	pivot = array[right];
	for (top = left - 1, down = right + 1; top < down;)
	{
		do {
			top++;
		} while (array[top] < pivot);
		do {
			down--;
		} while (array[down] > pivot);

		if (top < down)
		{
			swap_integer(array + top, array + down);
			print_array(array, size);
		}
	}

	return (top);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, p - 1);
		hoare_sort(array, size, p, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
