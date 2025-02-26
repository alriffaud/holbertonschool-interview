#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 *
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: pointer on the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *express = NULL, *prev = NULL;

	if (list == NULL)
		return (NULL);
	express = list;
	while (express->express != NULL)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		express->express->index, express->express->n);
		if (express->express->n >= value)
			break;
		express = express->express;
	}
	/* Determine range for linear search */
	prev = express;
	if (express->express && express->express->n >= value)
		express = express->express;
	else
	{
		while (express->next)
			express = express->next;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, express->index);
	/* Perform linear search in determined range */
	while (prev != NULL && prev->index <= express->index)
	{
		printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
