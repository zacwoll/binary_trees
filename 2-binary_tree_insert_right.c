#include "binary_trees.h"

/**
 * binary_tree_insert_right - creates a right binary tree node
 * @parent: parent node
 * @value: value
 * Return: binary_tree_t node or NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (!parent)
		return (NULL);
	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->parent = parent;
	new->n = value;
	new->left = NULL;
	if (parent->right)
		parent->right->parent = new;
	new->right = parent->right;
	parent->right = new;

	return (new);
}
