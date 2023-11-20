#include "sort.h"

/**
 * swap - Swaps the positions of two elements in an array
 * @array: The array
 * @a: Index of the first element
 * @b: Index of the second element
 */
void swap(int *array, size_t a, size_t b)
{
	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}

/**
 * lomuto_partition - Lomuto partition sorting scheme implementation
 * @array: The array to be partitioned
 * @low: The first index of the array
 * @high: The last index of the array
 * @size: The size of the array
 *
 * Return: The position of the last element after partitioning
 */
int lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t current = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (array[current] != array[j])
			{
				swap(array, current, j);
				print_array(array, size);
			}
			current++;
		}
	}

	if (array[current] != array[high])
	{
		swap(array, current, high);
		print_array(array, size);
	}

	return (current);
}

/**
 * quick_sort_recursion - Quick sort algorithm implementation (helper function)
 * @array: The array to be sorted
 * @low: The first index of the array
 * @high: The last index of the array
 * @size: The size of the array
 */
void quick_sort_recursion(int *array, int low, int high, size_t size)
{
	int position;

	if (low < high)
	{
		position = lomuto_partition(array, low, high, size);

		quick_sort_recursion(array, low, position - 1, size);
		quick_sort_recursion(array, position + 1, high, size);
	}
}

/**
 * quick_sort - Prepares the terrain for the Quick sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursion(array, 0, size - 1, size);
}
