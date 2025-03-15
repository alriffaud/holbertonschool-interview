#include "binary_trees.h"
#include <limits.h>
#include <stdlib.h>


/**
 * binary_tree_node - Creates a binary tree node.
 * @parent: Pointer to the parent node of the node to create.
 * @value: Value to put in the new node.
 *
 * Return: Pointer to the new node, or NULL on failure.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}


/**
 * tree_height - Computes the height of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Height of the tree.
 */
static int tree_height(const binary_tree_t *tree)
{
	int left_h, right_h;

	/* Base case: if tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/* Recursively compute the height of left and right subtrees */
	left_h = tree_height(tree->left);
	right_h = tree_height(tree->right);

	/* Return the greater height plus one for the current node */
	return ((left_h > right_h ? left_h : right_h) + 1);
}


/**
 * is_bst - Checks if a binary tree is a valid BST.
 * @tree: Pointer to the current node.
 * @min: Minimum allowed value for the current subtree.
 * @max: Maximum allowed value for the current subtree.
 *
 * Return: 1 if the subtree is a BST, 0 otherwise.
 */
static int is_bst(const binary_tree_t *tree, int min, int max)
{
	/* An empty tree is a valid BST */
	if (tree == NULL)
		return (1);

	/* Check current node value against allowed range */
	if (tree->n <= min || tree->n >= max)
		return (0);

	/* Recursively check left and right subtrees with updated ranges */
	return (is_bst(tree->left, min, tree->n) &&
			is_bst(tree->right, tree->n, max));
}


/**
 * is_balanced - Checks if a binary tree is balanced according to AVL rules.
 * @tree: Pointer to the current node.
 *
 * Return: 1 if the tree is balanced, 0 otherwise.
 */
static int is_balanced(const binary_tree_t *tree)
{
	int left_h, right_h;

	/* An empty tree is considered balanced */
	if (tree == NULL)
		return (1);

	/* Compute the height of left and right subtrees */
	left_h = tree_height(tree->left);
	right_h = tree_height(tree->right);

	/* Check if the current node is balanced */
	if (abs(left_h - right_h) > 1)
		return (0);

	/* Recursively check if left and right subtrees are balanced */
	return (is_balanced(tree->left) && is_balanced(tree->right));
}


/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL Tree, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	/* Return 0 if the tree is NULL */
	if (tree == NULL)
		return (0);

	/* Check if tree is a valid BST with proper value ranges */
	if (!is_bst(tree, INT_MIN, INT_MAX))
		return (0);

	/* Check if tree is balanced according to AVL conditions */
	if (!is_balanced(tree))
		return (0);

	return (1);
}
