#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 *              using the Shell sort algorithm with Knuth sequence.
 * @array: Array of integers to be sorted.
 * @size: Number of elements in the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* Calculate the initial gap value using Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		/* Perform insertion sort for each gap */
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;
			/* Shift elements until the correct position for temp is found */
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
		/* Decrease the gap */
		gap /= 3;
	}
}
