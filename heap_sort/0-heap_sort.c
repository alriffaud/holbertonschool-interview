#include "sort.h"


/**
 * swap - Swaps two integers in an array.
 * @a: First integer.
 * @b: Second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Maintains the max-heap property for a subtree rooted at index i.
 * @array: Array of integers.
 * @size: Size of the heap.
 * @i: Root index of the subtree.
 * @total: Total size of the array (for printing purposes).
 */
void heapify(int *array, size_t size, size_t i, size_t total)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[left] > array[largest])
		largest = left;

	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, total); /* Print the array after each swap */
		heapify(array, size, largest, total);
	}
}

/**
 * heap_sort - Sorts an array using the Heap Sort algorithm.
 * @array: Array of integers.
 * @size: Size of the array.
 */
void heap_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Build max-heap */
	for (int i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, i, size);

	/* Extract elements from heap one by one */
	for (int i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size); /* Print the array after each swap */
		heapify(array, i, 0, size);
	}
}
