#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - this function inserts a number into a sorted singly linked
 * list.
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new node or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	/* Insert at the beginning or into an empty list */
	if (*head == NULL || (*head)->n > number)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	current = *head;
	/* Find the correct position to insert the new node */
	while (current->next != NULL && current->next->n < number)
		current = current->next;
	/* Insert the new node in the correct position */
	new->next = current->next;
	current->next = new;

	return (new);
}
