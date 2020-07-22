#include "binary_trees.h"

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

/* find correct parent
 * node node
 * place in left or right of parent
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
