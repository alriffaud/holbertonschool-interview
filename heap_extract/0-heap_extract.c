#include "binary_trees.h"
#include <stdlib.h>

/**
 * heapify_down - Restores the max-heap property starting from a node
 * @node: Pointer to the current node
 */
void heapify_down(heap_t *node)
{
	heap_t *largest = node, *left = node->left, *right = node->right;
	int temp;

	if (left && left->n > largest->n)
		largest = left;
	if (right && right->n > largest->n)
		largest = right;

	if (largest != node)
	{
		temp = node->n;
		node->n = largest->n;
		largest->n = temp;
		heapify_down(largest);
	}
}

/**
 * get_last_node - Finds the last node in level-order traversal
 * @root: Pointer to the root of the heap
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	heap_t *queue[1024];
	int front = 0, rear = 0;
	heap_t *node = NULL;

	if (!root)
		return (NULL);

	queue[rear++] = root;
	while (front < rear)
	{
		node = queue[front++];
		if (node->left)
			queue[rear++] = node->left;
		if (node->right)
			queue[rear++] = node->right;
	}
	return (node);
}

/**
 * heap_extract - Extracts the root node of a max binary heap
 * @root: Double pointer to the root of the heap
 * Return: Value of the root node or 0 if fails
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node, *parent;
	int value;

	if (!root || !*root)
		return (0);

	last_node = get_last_node(*root);
	value = (*root)->n;

	if (last_node == *root)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	parent = last_node->parent;
	(*root)->n = last_node->n;

	if (parent->left == last_node)
		parent->left = NULL;
	else
		parent->right = NULL;

	free(last_node);
	heapify_down(*root);

	return (value);
}
