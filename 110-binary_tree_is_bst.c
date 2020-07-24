#include "binary_trees.h"

/**
 * is_bst - checks if a binary search tree qualifies
 * @tree: binary tree to be checked
 * @min: minimum value
 * @max: maximum value
 * Return: 1 if true, else 0
 */
int is_bst(const binary_tree_t *tree, const binary_tree_t *min,
		const binary_tree_t *max)
{
	if (!tree)
		return (1);
	if (min && min->n >= tree->n)
		return (0);
	if (max && max->n <= tree->n)
		return (0);

	return (is_bst(tree->left, min, tree) & is_bst(tree->right, tree, max));
}

/**
 * binary_tree_is_bst - checks if a binary search tree qualifies
 * @tree: binary tree to be checked
 * Return: 1 if true, else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_bst(tree, NULL, NULL));
}
