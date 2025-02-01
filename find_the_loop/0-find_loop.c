#include "lists.h"


/**
 * find_listint_loop - Find the loop in a linked list
 *
 * @head: A pointer to the first element of a list
 *
 * Return: The address of the node where the loop starts. NULL otherwise
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	/* If the list is empty, there is no cycle */
	if (head == NULL)
		return (NULL);

	/* Step 1: Detect the cycle using two pointers */
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			/* A cycle was detected */
			/* Step 2: Find the beginning of the cycle */
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow);
		}
	}
	/* If you get here, there is no cycle */
	return (NULL);
}
