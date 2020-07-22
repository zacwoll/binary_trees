#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if binary tree node is root or not
 * @node: node to be checked
 * Return: 1 if root, else 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node || node->parent)
		return (0);
	return (1);
}
