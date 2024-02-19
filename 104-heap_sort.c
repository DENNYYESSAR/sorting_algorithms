#include "sort.h"

void swap_elements(int *a, int *b);
void max_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * swap_elements - Swaps two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap_elements(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heapify_down - Maintains the max-heap property starting from
 * a node downwards.
 * @array: The array to heapify.
 * @size: The size of the array.
 * @base: The base index for the heapify operation.
 * @root: The root index.
 */
void heapify_down(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, largest;

	left = 2 * root + 1;
	right = 2 * root + 2;
	largest = root;

	if (left < base && array[left] > array[largest])
		largest = left;
	if (right < base && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap_elements(&array[root], &array[largest]);
		print_array(array, size);
		heapify_down(array, size, base, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using heap sort.
 * @array: The array to sort.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify_down(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap_elements(&array[0], &array[i]);
		print_array(array, size);
		heapify_down(array, size, i, 0);
	}
}
