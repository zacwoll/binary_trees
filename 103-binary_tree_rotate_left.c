#include "binary_trees.h"

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *node = NULL;

	if (!tree || !tree->right)
		return (tree);

	node = tree->right;
	tree->right = node->left;
	if (node->left)
		node->left->parent = tree;
	node->left = tree;
	tree->parent = node;

	return (node);
}
