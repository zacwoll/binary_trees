#include "binary_trees.h"

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	if (!parent)
		return (NULL);
	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	
	new->parent = parent;
	new->right = NULL;
	new->n = value;
	
	if (parent->left)
		parent->left->parent = new;

	new->left = parent->left;
	parent->left = new;
	
	return (new);
}
