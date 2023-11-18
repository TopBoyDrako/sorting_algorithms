#include "sort.h"
#include <stdio.h>
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
	int temp, min;
	bool swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		min = array[i];

		for (j = i + 1; j < size; j++)
		{
			if (min > array[j])
			{
				min = array[j];
				temp = j;
				swapped = true;
			}
		}
		if (swapped)
		{
			array[temp] = array[i];
			array[i] = min;

			print_array(array, size);
		}
	}

}
