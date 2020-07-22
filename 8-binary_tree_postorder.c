#include "binary_trees.h"

/**
 * binary_tree_postorder - passes values to a function from a binary tree
 * @tree: tree to be traversed
 * @func: function to be passed
 */
void binary_tree_postorder(const binary_tree_t *tree, void(*func)(int))
{
	if (!tree || !func)
		return;
	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
