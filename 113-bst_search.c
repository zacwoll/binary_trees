#include "binary_trees.h"

/**
 * bst_search - searches a binary search tree for a value
 * @tree: binary tree to be searched
 * @value: key to search for
 * Return: bst_t *node or NULLL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (value > tree->n)
		return (bst_search(tree->right, value));
	if (value < tree->n)
		return (bst_search(tree->left, value));
	return ((bst_t *)tree);
}
