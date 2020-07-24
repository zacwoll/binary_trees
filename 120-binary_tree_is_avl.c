#include "binary_trees.h"

/**
 * binary_tree_balance - calculates balance of binary tree
 * @tree: tree to be traversed
 * Return: int representing balance of binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int lh, rh;

	if (!tree)
		return (0);

	lh = binary_tree_height(tree->left);
	rh = binary_tree_height(tree->right);

	return (lh - rh);
}

/**
* binary_tree_height - calculates height of binary tree
* @tree: tree to be traversed
* Return: 0, 1, or total height thus far.
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lh, rh;

	if (!tree)
		return (0);

	lh = binary_tree_height(tree->left);
	rh = binary_tree_height(tree->right);

	if (lh >= rh)
		return (lh + 1);
	else
		return (rh + 1);
}

/**
 * is_bst - checks if a binary tree is a perfect binary search  tree
 * @tree: tree to be checked
 * @min: minimum value of subtree
 * @max: maximum value of subtree
 * Return: 1 if perfect, else 0
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
 * is_balanced - checks if a binary tree is balanced
 * @tree: tree to be checked
 * Return: 1 if balanced, else 0
 */
int is_balanced(const binary_tree_t *tree)
{
	int balance;

	if (!tree)
		return (1);

	balance = binary_tree_balance(tree);
	if ((balance >= -1 && balance <= 1) && is_balanced(tree->left)
			&& is_balanced(tree->right))
		return (1);
	return (0);
}

/**
 * binary_tree_is_avl - checks if a binary tree is avl
 * @tree: tree to be checked
 * Return: 1 if AVL, else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (is_bst(tree, NULL, NULL) && is_balanced(tree))
		return (1);
	return (0);
}
