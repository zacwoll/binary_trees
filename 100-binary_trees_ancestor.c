#include "binary_trees.h"

int is_ancestor(const binary_tree_t *search, const binary_tree_t *key,
		const binary_tree_t *prev)
{
	/* this algorithm is inefficient, one idea is to add a 'seen' value */
	if (!search || search == prev)
		return (0);
	if (search == key)
		return (1);
	return (is_ancestor(search->left, key, prev) |
			is_ancestor(search->right, key, prev));
}

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *search = (binary_tree_t *)first;
	binary_tree_t *prev = NULL;

	while (search)
	{
		if (is_ancestor(search, second, prev))
			return (search);
		prev = search;
		search = search->parent;
	}

	return (NULL);
}
