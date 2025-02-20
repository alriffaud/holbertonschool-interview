#include "list.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - Adds a new node to the end of a double circular linked list.
 * @list: Pointer to the head of the list.
 * @str: String to be copied into the new node.
 *
 * Return: Address of the new node, or NULL on failure.
 */
List *add_node_end(List **list, char *str)
{
	List *new_node;
	List *last;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);
	/* Duplicate the string and assign it to the new node's str field */
	new_node->str = strdup(str);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	/* If the list is empty, initialize new node's next and prev pointers */
	/* to itself */
	if (*list == NULL)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		*list = new_node;
	}
	else
	{
		/* Get the last node using the fact that (*list)->prev points to the */
		/* last element */
		last = (*list)->prev;
		/* Insert new node between last and the head (*list) */
		new_node->next = *list;
		new_node->prev = last;
		last->next = new_node;
		(*list)->prev = new_node;
	}
	return (new_node);
}

/**
 * add_node_begin - Adds a new node to the beginning of a double circular
 * linked list.
 * @list: Pointer to the head of the list.
 * @str: String to be copied into the new node.
 *
 * Return: Address of the new node, or NULL on failure.
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node;

	/* Reuse add_node_end to add the new node to the list */
	new_node = add_node_end(list, str);
	if (new_node != NULL)
		/* Update the head pointer to point to the new node */
		*list = new_node;
	return (new_node);
}
