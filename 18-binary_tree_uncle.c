#include "binary_trees.h"

/**
 * binary_tree_uncle - checks if a binary tree has an uncle
 * @node: binary tree to be checked
 * Return: binary_tree_t * or NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);
	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);
	else
		return (node->parent->parent->left);
}
