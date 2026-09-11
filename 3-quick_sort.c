#include "sort.h"

/**
 * swap_ints - swaps two integers in an array
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - partitions an array using the Lomuto scheme,
 * with the last element as the pivot
 * @array: the array to partition
 * @lo: starting index of the partition
 * @hi: ending index of the partition (pivot index)
 * @size: the number of elements in array, for printing
 *
 * Return: the final index of the pivot after partitioning
 */
int lomuto_partition(int *array, int lo, int hi, size_t size)
{
	int pivot, i, j;

	pivot = array[hi];
	i = lo - 1;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap_ints(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (i + 1 != hi)
	{
		swap_ints(&array[i + 1], &array[hi]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_recursive - recursively sorts a partition of an array
 * using Quick sort with Lomuto partitioning
 * @array: the array to sort
 * @lo: starting index of the partition
 * @hi: ending index of the partition
 * @size: the number of elements in array, for printing
 */
void quick_sort_recursive(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = lomuto_partition(array, lo, hi, size);
		quick_sort_recursive(array, lo, p - 1, size);
		quick_sort_recursive(array, p + 1, hi, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using
 * the Quick sort algorithm (Lomuto partition scheme)
 * @array: the array to sort
 * @size: the number of elements in array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, (int)size - 1, size);
}
