#include "sort.h"

void swap_ints(int *a, int *b);

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Partition the array using Lomuto scheme
 * @array: Array to be partitioned
 * @size: Size of the array
 * @left: Starting index of the partition
 * @right: Ending index of the partition
 * Return: Index of the pivot after partitioning
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int pivot = array[right];
	int i = left - 1;
	int j;

	for (j = left; j <= right - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_ints(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}
	swap_ints(&array[i + 1], &array[right]);
	if (i + 1 != right)
		print_array(array, size);
	return (i + 1);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
