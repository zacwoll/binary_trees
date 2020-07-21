#include "binary_trees.h"

int is_ancestor(const binary_tree_t *search, const binary_tree_t *key)
{
	if (!search)
		return (0);
	if (search == key)
		return (1);
	return (ancestor(search->left, key) | ancestor(search->right, key));
}

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *search = (binary_tree_t *)first;

	while (search)
	{
		if (is_ancestor(search, second))
			return (search);
		search = search->parent;
	}

	return (NULL);
}
