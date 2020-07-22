#include "binary_trees.h"

/**
 * binary_tree_inorder - passes values to a function from a binary tree
 * @tree: tree to be traversed
 * @func: function to be passed
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	binary_tree_inorder(tree->left, func);
	func(tree->n);
	binary_tree_inorder(tree->right, func);
}
