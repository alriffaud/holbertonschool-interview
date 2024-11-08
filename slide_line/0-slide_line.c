#include "slide_line.h"

/**
 * compact_line - Compacts non-zero elements to the left or right
 * @line: Array of integers
 * @size: Size of the array
 * @direction: Direction to compact (SLIDE_LEFT or SLIDE_RIGHT)
 */
void compact_line(int *line, size_t size, int direction)
{
	int temp[size];
	size_t i, idx = 0;

	/* Initialize temp array to zero */
	for (i = 0; i < size; i++)
		temp[i] = 0;

	/* Copy non-zero elements to temp array based on direction */
	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size; i++)
		{
			if (line[i] != 0)
				temp[idx++] = line[i];
		}
	}
	else /* SLIDE_RIGHT */
	{
		for (i = size; i > 0; i--)
		{
			if (line[i - 1] != 0)
				temp[size - idx++ - 1] = line[i - 1];
		}
	}

	/* Copy back to original line */
	for (i = 0; i < size; i++)
		line[i] = temp[i];
}

/**
 * slide_line - Slides and merges an array of integers
 * @line: points to an array of integers containing size elements
 * @size: size of the array
 * @direction: direction to slide and merge
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	/* Compact elements before merging */
	compact_line(line, size, direction);

	/* Merge adjacent elements */
	if (direction == SLIDE_LEFT)
	{
		for (i = 0; i < size - 1; i++)
		{
			if (line[i] == line[i + 1] && line[i] != 0)
			{
				line[i] *= 2;
				line[i + 1] = 0;
			}
		}
		/* Compact again after merging */
		compact_line(line, size, SLIDE_LEFT);
	}
	else /* SLIDE_RIGHT */
	{
		for (i = size - 1; i > 0; i--)
		{
			if (line[i] == line[i - 1] && line[i] != 0)
			{
				line[i] *= 2;
				line[i - 1] = 0;
			}
		}
		/* Compact again after merging */
		compact_line(line, size, SLIDE_RIGHT);
	}

	return (1);
}
