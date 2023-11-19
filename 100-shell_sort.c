#include "sort.h"

/**
*swapper - Swaps the positions of two elements into an array
*@array: array
*@item1: array element
*@item2: array element
*/
void swapper(int *array, int item1, int item2)
{

	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 * shell_sort - function that sorts an array of integers
 * @size: size of the array
 * @array: list with numbers
 */
void shell_sort(int *array, size_t size)
{
	size_t hiat = 1, i, index = 0;

	if (array == NULL || size < 2)
		return;
	while (hiat < size / 3)
		hiat = 3 * hiat + 1;
	while (hiat >= 1)
	{
		for (i = hiat; i < size; i++)
			for (index = i; index >= hiat &&
			 (array[index] < array[index - hiat]); index -= hiat)
				swapper(array, index, index - hiat);
		print_array(array, size);
		hiat /= 3;
	}
}
