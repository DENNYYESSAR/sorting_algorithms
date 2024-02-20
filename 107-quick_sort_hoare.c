#include "sort.h"

void swap_integers(int *a, int *b);
void quick_sort_hoare(int *array, size_t size);
int my_hoare_partition(int *array, size_t size, int left, int right);
void my_hoare_sort(int *array, size_t size, int left, int right);

/**
 * swap_integers - Exchange the values of two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap_integers(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * my_hoare_partition - Partition a subset of an array based on Hoare scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset.
 * @right: The ending index of the subset.
 *
 * Return: The final index of the partition.
 *
 * Description: The pivot is the last element.
 * Prints the array after each swap.
 */
int my_hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_integers(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * my_hoare_sort - Implement quicksort using the Hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the partition.
 * @right: The ending index of the partition.
 *
 * Description: Recursively sorts the array.
 */
void my_hoare_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = my_hoare_partition(array, size, left, right);
		my_hoare_sort(array, size, left, part - 1);
		my_hoare_sort(array, size, part, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending order.
 * @array: The array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme and prints array
 * after each swap.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	my_hoare_sort(array, size, 0, size - 1);
}
