#include "binary_trees.h"

/**
 * binary_tree_size - calculates total leaves in binary tree
 * @tree: tree to be traversed
 * Return: size_t size of binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
