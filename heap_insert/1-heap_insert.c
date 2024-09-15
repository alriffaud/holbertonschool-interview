#include <stdlib.h>
#include "binary_trees.h"


/**
 * swap_values - Exchange values ​​between two nodes
 * @node_a: First node to exchange
 * @node_b: Second node to exchange
 */
void swap_values(heap_t *node_a, heap_t *node_b)
{
	int temp;

	temp = node_a->n;
	node_a->n = node_b->n;
	node_b->n = temp;
}

/**
 * find_insertion_point - Find the first available point to insert a new node.
 * Perform a Breadth First Search (BFS) traversal to find the first node.
 * @root: Pointer to the root node of the heap
 *
 * Return: Pointer to the first available node, or NULL if the heap is NULL.
 */
heap_t *find_insertion_point(heap_t *root)
{
	heap_t *queue[1024];
	int front = 0, rear = 0;

	if (!root)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		heap_t *current = queue[front++];

		if (!current->left || !current->right)
			return (current);

		queue[rear++] = current->left;
		queue[rear++] = current->right;
	}

	return (NULL);
}

/**
 * heap_insert - Insert a value in Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the new node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL, *parent = NULL;

	if (root == NULL)
		return (NULL);

	/* If the tree is empty, we create the root node */
	if (*root == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*root = new_node;
		return (new_node);
	}
	/* Finding the first available insert location using BFS */
	parent = find_insertion_point(*root);
	if (!parent)
		return (NULL);
	/* Creating the new node and assigning it to the correct location */
	new_node = binary_tree_node(parent, value);
	if (!new_node)
		return (NULL);

	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;

	/**
	* Swap the values of the new node with its parent until the new node
	* is greater than its parent or until the new node is the root node.
	*/
	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		swap_values(new_node, new_node->parent);
		new_node = new_node->parent;
	}

	return (new_node);
}
