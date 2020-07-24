#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotates a binary tree to the left
 * @tree: tree to be rotated
 * Return: new root of binary tree or NULL
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *node, *tree_parent;

	if (!tree)
		return (NULL);

	node = tree->right;
	if (node)
	{
		tree_parent = tree->parent;
		if (tree->parent)
		{
			if (tree->parent->left == tree)
				tree->parent->left = node;
			else
				tree->parent->right = node;
		}
		tree->right = node->left;
		if (node->left)
			node->left->parent = tree;
		tree->parent = node;
		node->left = tree;
		node->parent = tree_parent;
	}
	while (tree->parent)
		tree = tree->parent;
	return (tree);
}
