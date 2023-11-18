#include "sort.h"
#include <stdbool.h>

/**
 * selection_sort- implementation of the selection sort algo
 *
 * @array: an array of integers
 * @size: size of the array
 */

void selection_sort(int *array, size_t size)
{
	unsigned int i, j;
	int min, min_index;
	bool min_changed;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		min_changed = false;

		for (j = i + 1; j < size; j++)
		{
			if (array[min_index] > array[j])
			{
				min_index = j;
				min_changed = true;
			}
		}
		if (min_changed)
		{
			min = array[min_index];
			array[min_index] = array[i];
			array[i] = min;

			print_array(array, size);
		}
	}
}
