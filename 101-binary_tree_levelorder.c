#include "binary_trees.h"

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

/**
 * binary_tree_print_given_level - print all nodes at a given level
 * @tree: tree to be printed
 * @level: Given height of the binary tree to print at
 * @func: function that prints each node
 */
void binary_tree_print_given_level(const binary_tree_t *tree,
		size_t level, void (*func)(int))
{
	if (!tree)
		return;
	if (level == 0)
		func(tree->n);
	else
	{
		binary_tree_print_given_level(tree->left, level - 1, func);
		binary_tree_print_given_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - traverse a binary tree in level order
 * @tree: binary tree to be traversed
 * @func: function that prints each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	if (!tree || !func)
		return;

	height = binary_tree_height(tree);

	for (i = 0; i <= height; i++)
		binary_tree_print_given_level(tree, i, func);
}


