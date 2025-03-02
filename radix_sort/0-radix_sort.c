#include "sort.h"
#include <stdlib.h>


/**
 * get_max - Helper function to get the maximum value in the array.
 * @array: Pointer to the array.
 * @size: Number of elements in the array.
 * Return: The maximum value in the array.
 */
static int get_max(int *array, size_t size)
{
	int max = array[0];
	int i;

	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}


/**
 * radix_count_sort - Helper function that performs counting sort based on the
 * current digit.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 * @exp: Current exponent (power of 10).
 * @output: Pointer to the output array.
 */
static void radix_count_sort(int *array, size_t size, size_t exp, int *output)
{
	int count[10] = {0};
	int i, digit;

	/* Count the occurrences of each digit at the current exponent */
	for (i = 0; i < (int)size; i++)
	{
		digit = (array[i] / exp) % 10;
		count[digit]++;
	}
	/* Convert count array to cumulative count */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	/* Build the output array in a stable manner */
	for (i = (int)size - 1; i >= 0; i--)
	{
		digit = (array[i] / exp) % 10;
		output[count[digit] - 1] = array[i];
		count[digit]--;
	}
	/* Copy the output array back to the original array */
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - Sorts an array of integers using the LSD Radix sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void radix_sort(int *array, size_t size)
{
	int max;
	size_t exp;
	int *output;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	/* Process each digit, starting from the least significant digit */
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		radix_count_sort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
