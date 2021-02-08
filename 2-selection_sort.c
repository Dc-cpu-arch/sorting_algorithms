#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order with
 * Selection Sort Algorithm
 *
 * @array: location to the array
 * @size: array size
 */

void selection_sort(int *array, size_t size)
{
	unsigned int step, crnt, min;
	int tmp;

	if (size < 2)
		return;

	for (step = 0; step < size - 1; step++)
	{
		min = step;
		for (crnt = step + 1; crnt < size; crnt++)
		{
			if (array[crnt] < array[min])
				min = crnt;
		}
		if (crnt != step)
		{
			tmp = array[step];
			array[step] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
	}
}
