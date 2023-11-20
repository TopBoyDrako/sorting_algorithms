#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
* quick_sort - Sorts an array of integers in ascending order using Quick sort
* @array: The array to be sorted
* @size: The size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_callback(array, 0, size - 1, size);
}


/**
* lomuto_partition - This is a quicksort sorting scheme implemntation 
* @array: array
* @less: first element in array
* @great: last element in array
* @size: size of the array
*
* Return: The index of he pivot of partitioning 
*/

int lomuto_partition(int *array, int less, int great, size_t size)
{
	int pivot = array[great];
	int i = less - 1;
	int j, temp;

	for (j = less; j <= great - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[great];
	array[great] = temp;
	print_array(array, size);


	return i + 1;
}

/*
* quick_sort_callback - implementation for the quicksort algorithm
* @array: array
* @less: first element in array
* @great: last element in array
*/

void quick_sort_callback(int *array, int less, int great, size_t size)
{
	if (less < great)
	{
        int pivot_index = lomuto_partition(array, less, great, size);

        quick_sort_callback(array, less, pivot_index - 1, size);
        quick_sort_callback(array, pivot_index + 1, great, size);
	}
}
