#include "sort.h"

/**
 * merge - Merges two subarrays into a sorted order
 * @array: The original array
 * @left: Left subarray
 * @right: Right subarray
 * @size_left: Size of the left subarray
 * @size_right: Size of the right subarray
 */
void merge(int *array, int *left, int *right, size_t size_left,
size_t size_right)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = malloc((size_left + size_right) * sizeof(int));

	if (!temp)
		return;

	printf("Merging...\n[left]: ");
	print_array(left, size_left);
	printf("[right]: ");
	print_array(right, size_right);

	while (i < size_left && j < size_right)
	{
		if (left[i] <= right[j])
			temp[k++] = left[i++];
		else
			temp[k++] = right[j++];
	}
	while (i < size_left)
		temp[k++] = left[i++];
	while (j < size_right)
		temp[k++] = right[j++];

	for (i = 0; i < size_left + size_right; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array, size_left + size_right);
	free(temp);
}

/**
 * merge_sort_rec - Recursively sorts an array using merge sort
 * @array: The array to sort
 * @size: The size of the array
 */
void merge_sort_rec(int *array, size_t size)
{
	if (size < 2)
		return;

	size_t mid = size / 2;
	int *left = array;
	int *right = array + mid;
	size_t size_left = mid;
	size_t size_right = size - mid;

	merge_sort_rec(left, size_left);
	merge_sort_rec(right, size_right);
	merge(array, left, right, size_left, size_right);
}

/**
 * merge_sort - Sorts an array using merge sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	merge_sort_rec(array, size);
}
