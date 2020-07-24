#include "binary_trees.h"

/**
 * bst_search - searches a binary search tree for a value
 * @tree: binary tree to be searched
 * @value: key to search for
 * Return: bst_t *node or NULLL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (value > tree->n)
		return (bst_search(tree->right, value));
	if (value < tree->n)
		return (bst_search(tree->left, value));
	return ((bst_t *)tree);
}

/**
 * in_order_successor - finds the next in-order successor to a binary tree node
 * @root: root of binary tree to search
 * Return: bst_t *successor or NULL
 */
bst_t *in_order_successor(bst_t *root)
{
	if (!root || (!root->right && !root->left))
		return (NULL);
	if (!root->right)
	{
		root = root->left;
		while (root->right)
			root = root->right;
		return (root);
	}
	root = root->right;
	while (root->left)
		root = root->left;
	return (root);
}

/**
 * bst_remove - removes a node from a binary tree
 * @root: root of binary tree to search
 * @value: key of node to remove
 * Return: bst_t *root or NULL
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *delete = NULL;
	bst_t *successor = NULL;

	if (!root)
		return (NULL);
	/* find node to be deleted */
	delete = bst_search(root, value);
	if (!delete)
		return (NULL);
	/* find successor */
	successor = in_order_successor(delete);
	if (!successor)
		return (NULL);
	/* replace data */
	delete->n = successor->n;
	/* remove leaf or find new successor */
	if (!successor->left && !successor->right)
	{
		if (successor == successor->parent->right)
			successor->parent->right = NULL;
		else
			successor->parent->left = NULL;
		free(successor);
		return (root);
	}
	else
	{
		if (!delete->right)
			bst_remove(delete->left, successor->n);
		else
			bst_remove(delete->right, successor->n);
	}
	return (root);
}
