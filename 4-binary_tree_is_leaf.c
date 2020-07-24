#include "binary_trees.h"

/**
 * binary_tree_is_leaf - checks if binary tree node is leaf or not
 * @node: node to be checked
 * Return: 1 if leaf, else 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node && !node->left && !node->right)
		return (1);
	else
		return (0);
}
