#include "binary_trees.h"

/**
 * array_to_bst - creates a binary search tree from an array
 * @array: array to draw values from
 * @size: size of array
 * Return: bst_t *ptr of array or NULL
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		bst_insert(&tree, array[i]);
	}

	return (tree);
}
