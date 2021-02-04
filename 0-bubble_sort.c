#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 * if [idx] > [idx + 1] then put the largest value on the right.
 * In the first step the largest number will be in the last idx
 * so we don't need that idx in the second step, and so on.
 *
 * @array: of integers
 * @size: number of elements inside array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int step, idx;
	int tmp;

	if (!array || size < 2)
		return;

	/* every step the array is crossed each time one idx less */
	for (step = 0; step < size - 1; step++)
	{
		/* compare all elements that need to be sorted */
		for (idx = 0; idx < size - step - 1; idx++)
		{
			if (array[idx] > array[idx + 1])
			{
				tmp = array[idx];
				array[idx] = array[idx + 1];
				array[idx + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
