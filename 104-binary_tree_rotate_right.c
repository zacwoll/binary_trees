#include "binary_trees.h"

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *node = NULL;

	if (!tree || !tree->left)
		return (tree);

	node = tree->left;
	tree->left = node->right;
	if (node->right)
		node->right->parent = tree;
	node->right = tree;
	tree->parent = node;

	return (node);
}
