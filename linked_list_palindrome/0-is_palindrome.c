#include "lists.h"


/**
 * add_nodeint_begin - adds a new node at the beginning of a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @n: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *add_nodeint_begin(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to head of list
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	listint_t *new_list = NULL, *current, *current2;
	int res;

	current = *head;

	if (*head == NULL || (*head)->next == NULL)
		return (1);

	/* Copy the list in reverse order */
	while (current != NULL)
	{
		add_nodeint_begin(&new_list, current->n);
		current = current->next;
	}

	/* Compare both lists */
	current = *head;
	current2 = new_list;
	while (current != NULL && current->n == current2->n)
	{
		current = current->next;
		current2 = current2->next;
	}
	if (current == NULL)
		res = 1;
	else
		res = 0;

	free_listint(new_list);
	return (res);
}
