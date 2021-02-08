#include "sort.h"

/**
 * quick_sort - sorts an array of integer in ascending order
 * with Quick Sort Algorith
 *
 * @array: location to the array
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	pivot_recursion(array, 0, size - 1, size);
}

/**
 * pivot_recursion - sets a pivot in the array and splits it
 * as many times as necessary
 *
 * @low: lowest value on the array or sub-array
 * @high: highest value on the array or sub-array
 * @size: array size
 */
void pivot_recursion(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = splition(array, low, high, size);
		pivot_recursion(array, low, pivot - 1, size);
		pivot_recursion(array, pivot + 1, high, size);
	}
}

/**
 * splition - splits the array and sub-arrays following lomuto scheme
 *
 * @array: location to the array
 * @low: lowest value
 * @high: highest value
 * @size: array size
 *
 * Return: partition index
 */
int splition(int *array, int low, int high, size_t size)
{
	int pivot = array[high], idx = low, step, temp;

	for (step = low; step < high; step++)
	{
		if (array[step] <= pivot)
		{
			if (idx != step)
			{
				temp = array[idx];
				array[idx] = array[step];
				array[step] = temp;
				print_array(array, size);
			}
			idx++;
		}
	}
	if (idx != step)
	{
		temp = array[idx];
		array[idx] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (idx);
}
