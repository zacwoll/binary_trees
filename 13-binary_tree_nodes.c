#include "binary_trees.h"

/**
 * binary_tree_nodes - counts number of nodes in binary tree
 * @tree: tree to be traversed
 * Return: size_t number of nodes in binary tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->left || tree->right)
	{
		return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right)
				+ 1);
	}
	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
