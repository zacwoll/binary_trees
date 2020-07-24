#include "binary_trees.h"

/**
 * binary_tree_is_perfect - checks if a binary tree is perfectly balanced
 * @tree: tree to be traversed
 * Return: 0, 1, or total height thus far.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (binary_tree_height(tree->left) != binary_tree_height(tree->right))
		return (0);
	if (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_perfect(tree->right))
		return (1);
	return (0);
}

/**
 * binary_tree_height - calculates height of binary tree
 * @tree: tree to be traversed
 * Return: 0, 1, or total height thus far.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lh, rh;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	lh = binary_tree_height(tree->left);
	rh = binary_tree_height(tree->right);

	if (lh >= rh)
		return (lh + 1);
	else
		return (rh + 1);
}
