#include "sort.h"
#include <stdbool.h>

/**
 * bubble_sort - implementation of bubble sort
 *
 * @array: an array of integers to be sorted
 * @size: number of elements in the array
 */

void bubble_sort(int *array, size_t size)
{
	int i, j, temp;
	bool swapped;

	for (i = size - 1; i >= 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			swapped = false;

			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = true;

				print_array(array, size);
			}
		}
		if (!swapped)
			break;
	}

}
