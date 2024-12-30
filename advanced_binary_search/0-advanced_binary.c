#include <stdio.h>
#include <stdlib.h>

/**
 * print_array - Prints an array of integers
 * @array: Pointer to the first element of the array to be printed
 * @left: Starting index of the subarray
 * @right: Ending index of the subarray
 */
void print_array(int *array, size_t left, size_t right)
{
	printf("Searching in array: ");
	for (size_t i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_search - Helper function to perform recursive binary search
 * @array: Pointer to the first element of the array to search in
 * @left: Starting index of the subarray
 * @right: Ending index of the subarray
 * @value: The value to search for
 *
 * Return: Index of the first occurrence of the value, or -1 if not found
 */
int recursive_search(int *array, size_t left, size_t right, int value)
{
	if (left > right)
		return (-1);

	print_array(array, left, right);

	size_t mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		/* Check if it's the first occurrence */
		if (mid == left || array[mid - 1] != value)
			return ((int)mid);
		return (recursive_search(array, left, mid, value));
	}
	else if (array[mid] > value)
		return (recursive_search(array, left, mid, value));
	else
		return (recursive_search(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array using binary search
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: The value to search for
 *
 * Return: Index of the first occurrence of the value, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (recursive_search(array, 0, size - 1, value));
}
