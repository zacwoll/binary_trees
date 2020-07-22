#include "binary_trees.h"

/**
 * binary_tree_sibling - checks if a binary tree has a sibling
 * @node: binary to be checked
 * Return: binary_tree_t * or NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node == node->parent->left)
		return (node->parent->right);
	else
		return (node->parent->left);
}
