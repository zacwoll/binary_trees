#include "binary_trees.h"

/**
 * _bst_insert - binary search tree insertion method
 * @tree: tree to be searched and inserted
 * @value: value to be placed in node
 * Return: bst * to node or NULL
 */
bst_t *_bst_insert(bst_t *tree, int value)
{
	if (value < tree->n)
	{
		if (tree->left)
			return (_bst_insert(tree->left, value));
		tree->left = binary_tree_node(tree, value);
		return (tree->left);
	}
	if (value > tree->n)
	{
		if (tree->right)
			return (_bst_insert(tree->right, value));
		tree->right = binary_tree_node(tree, value);
		return (tree->right);
	}
	return (NULL);
}

/**
 * bst_insert - insert into binary search tree
 * @tree: tree to be binary searched
 * @value: value to be inserted
 * Return: bst_t * or NULL
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}
	return (_bst_insert(*tree, value));
}
