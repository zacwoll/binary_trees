
#include "binary_trees.h"

/* algo is
 * add node to tree
 * rebalance tree
 * return added_node
 * well avl_insert.c works too bad its gay
 */

/**
 * _avl_insert - binary search tree insertion method
 * @tree: tree to be searched and inserted
 * @value: value to be placed in node
 * Return: avl * to node or NULL
 */
avl_t *_avl_insert(avl_t *tree, int value)
{
	avl_t *node;
	int bal;

	if (value < tree->n)
	{
		if (tree->left)
			return (_avl_insert(tree->left, value));
		tree->left = binary_tree_node(tree, value);
		node = tree->left;

		if (tree->parent)
		{
			bal = binary_tree_balance(tree);
			if (bal < 0)
				binary_tree_rotate_right(tree);
			else if (bal > 0)
				binary_tree_rotate_left(tree);
		}
		return (node);
	}
	if (value > tree->n)
	{
		if (tree->right)
			return (_avl_insert(tree->right, value));
		tree->right = binary_tree_node(tree, value);
		node = tree->right;

		if (tree->parent)
		{
			printf("tree->parent: %d\n", tree->parent->n);
			bal = binary_tree_balance(tree->parent);
			printf("tree %d/ tree->right %d\n", tree->n, tree->right->n);
			if (bal < -1)
				tree = binary_tree_rotate_right(tree->parent);
			else if (bal > 1)
				tree = binary_tree_rotate_left(tree->parent);
		}
		printf("===%d===\n", bal);
		binary_tree_print(tree);

		return (node);
	}
	return (NULL);
}

/**
 * avl_insert - insert into binary search tree
 * @tree: tree to be binary searched
 * @value: value to be inserted
 * Return: avl_t *created_node or NULL
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}
	return (_avl_insert(*tree, value));
}
