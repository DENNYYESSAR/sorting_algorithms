#include "sort.h"

void swap_integers(int *a, int *b);
void bitonic_sort(int *array, size_t size);
void bitonic_sequence(int *array, size_t size, size_t start, size_t seq,
		char flow);
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow);

/**
 * swap_integers - Swap two integers in an array.
 * @a: Pointer to the first integer to swap.
 * @b: Pointer to the second integer to swap.
 */
void swap_integers(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_merge - Merge a bitonic sequence within an array of integers.
 * @array: Array of integers.
 * @size: Size of the array.
 * @start: Starting index of the sequence in the array to sort.
 * @seq: Size of the sequence to sort.
 * @flow: Direction of sorting.
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((flow == UP && array[i] > array[i + jump]) ||
			    (flow == DOWN && array[i] < array[i + jump]))
				swap_integers(array + i, array + i + jump);
		}
		bitonic_merge(array, size, start, jump, flow);
		bitonic_merge(array, size, start + jump, jump, flow);
	}
}

/**
 * bitonic_sequence - Convert an array of integers into a bitonic sequence.
 * @array: Array of integers.
 * @size: Size of the array.
 * @start: Starting index of a block of the building bitonic sequence.
 * @seq: Size of a block of the building bitonic sequence.
 * @flow: Direction to sort the bitonic sequence block.
 */
void bitonic_sequence(int *array, size_t size, size_t start, size_t seq,
		char flow)
{
	size_t cut = seq / 2;
	char *direction = (flow == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, direction);
		print_array(array + start, seq);

		bitonic_sequence(array, size, start, cut, UP);
		bitonic_sequence(array, size, start + cut, cut, DOWN);
		bitonic_merge(array, size, start, seq, flow);

		printf("Result [%lu/%lu] (%s):\n", seq, size, direction);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending order using
 * Bitonic Sort.
 * @array: Array of integers to be sorted.
 * @size: Size of the array.
 *
 * Description: Prints the array after each swap. Works only for
 * size = 2^k where k >= 0.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sequence(array, size, 0, size, UP);
}
