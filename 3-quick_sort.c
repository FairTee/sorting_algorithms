#include "sort.h"

/**
*swapper - the positions of two elements into an array
*@array: array
*@item1: array element
*@item2: array element
*/
void swapper(int *array, ssize_t item1, ssize_t item2)
{
	int tmp;

	tmp = array[item1];
	array[item1] = array[item2];
	array[item2] = tmp;
}
/**
 *lomuto_partition - lomuto partition sorting scheme implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: size array
 *Return: return the position of the last element sorted
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int piv = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < piv)
		{
			if (array[current] != array[finder])
			{
				swapper(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}
	if (array[current] != array[last])
	{
		swapper(array, current, last);
		print_array(array, size);
	}
	return (current);
}
/**
 *quisor - qucksort algorithm implementation
 *@array: array
 *@first: first array element
 *@last: last array element
 *@size: array size
 */
void quisor(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t posi = 0;


	if (first < last)
	{
		posi = lomuto_partition(array, first, last, size);

		quisor(array, first, posi - 1, size);
		quisor(array, posi + 1, last, size);
	}
}
/**
 *quick_sort - prepare the terrain to quicksort algorithm
 *@array: array
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quisor(array, 0, size - 1, size);
}
