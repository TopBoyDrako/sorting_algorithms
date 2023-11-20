#include "sort.h"
#include <stdio.h>

/**
* swap - function to swap 2 integers
*
* @*a: int to swap
* @*b: int to swap
*/

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
* lomuto_partition - This is a quicksort sorting scheme implemntation 
* @array: array
* @less: first element in array
* @great: last element in array
*/

int lomuto_partition(int *array, int less, int great)
{
	int pivot = array[great];
	int i = less - 1;

	int j;
	for (j = less; j <= great - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}

	swap(&array[i + 1], &array[great]);
	return i + 1;
}

/*
* quick_sort_callback - implementation for the quicksort algorithm
* @array: array
* @less: first element in array
* @great: last element in array
*/

void quick_sort_callback(int *array, int less, int great)
{
	int i;
 
   if (less < great)
    {
        int pivot_index = lomuto_partition(array, less, great);

        quick_sort_callback(array, less, pivot_index - 1);
        quick_sort_callback(array, pivot_index + 1, great);

        for (i = less; i <= great; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
}

/**
* quick_sort - This is the function to sort an algorithm using quicksort
* @array: array of integers
* @size: size of the array
*/

void quick_sort(int *array, size_t size)
{
	quick_sort_callback(array, 0, size - 1);
}
