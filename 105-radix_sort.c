#include "sort.h"
#include <stdbool.h>

int cont_flag(int num);
/**
 * radix_sort - sorting using the radix method
 * @array: array
 * @size: size
 * Return: 0
 */
void radix_sort(int *array, size_t size)
{
	int z, j, x, y, flag, max, div = 1, t = 0;
	int bucket[10][1000];

	if (!array || size < 2)
		return;
	max = array[0];
	for (z = 1; z < (int) size; z++)
		if (array[z] > max)
			max = array[z];
	for (z = 0; z < 10; ++z)
		for (j = 0; j < 1000; ++j)
			bucket[z][j] = -1;
	flag = cont_flag(max);
	for (z = 0; z < flag; ++z)
	{
		for (j = 0; j < (int) size; ++j)
		{
			for (y = 0; bucket[(array[j] / div) % 10][y] != -1; y++)
				;
			bucket[(array[j] / div) % 10][y] = array[j];
		}
		div = div * 10;
		t = 0;
		for (x = 0; x < 10; ++x)
		{
			for (y = 0; bucket[x][y] != -1; y++)
			{
				array[t] = bucket[x][y];
				bucket[x][y] = -1;
				t++;
			}
		}
		print_array(array, size);
	}
}

/**
 * cont_flag - It has to
 * @num: largest number
 * Return: 0
 */
int cont_flag(int num)
{
	bool flag = true;
	int cont = 0;

	while (flag)
	{
		flag = false;
		if (num > 0)
		{
			num = num / 10;
			cont++;
			flag = true;
		}
	}
	return (cont);
}
