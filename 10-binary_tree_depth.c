#include "binary_trees.h"

/**
 * binary_tree_depth - calculates depth of binary tree
 * @tree: tree to be traversed
 * Return: 0, 1, size_t depth of tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);
	return (binary_tree_depth(tree->parent) + 1);
}
