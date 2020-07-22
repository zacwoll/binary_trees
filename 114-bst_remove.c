#include "binary_trees.h"

/* apparently the next in order successor unless there is no successor,
 * then it's the predecessor
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

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *delete = NULL;
	bst_t *successor = NULL;

	if (!root)
		return (NULL);
	printf("%d\n", root->n);
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
