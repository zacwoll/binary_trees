#include "binary_trees.h"

int binary_tree_balance(const binary_tree_t *tree)
{
	int lh, rh;

	if (!tree)
		return (0);

	lh = binary_tree_height(tree->left);
	rh = binary_tree_height(tree->right);

	return (lh - rh);
}

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
