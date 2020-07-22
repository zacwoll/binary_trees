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

/**
 * is_complete - Recur helper for binary_tree_is_complete
 * @tree: binary tree to check for completion
 * @index: index of node to be checked
 * @node_count: size of binary tree
 * Return: 1 if complete binary tree, else 0
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t node_count)
{
	if (!tree)
		return (1);
	if (index >= node_count)
		return (0);
	return (is_complete(tree->left, 2 * index + 1, node_count) &
			is_complete(tree->right, 2 * index + 2, node_count));
}

/**
 * binary_tree_is_complete - checks binary tree for completion
 * @tree: binary tree to be checked
 * Return: 1 if complete, else 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t node_count;

	if (!tree)
		return (0);

	node_count = binary_tree_size(tree);
	return (is_complete(tree, 0, node_count));
}
