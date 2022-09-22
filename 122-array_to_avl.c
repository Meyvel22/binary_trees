#include "binary_trees.h"

/**
 * array_to_avl - function that builds an AVL tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree;
	size_t x;

	tree = NULL;

	for (x = 0; x < size; x++)
	{
		avl_insert(&tree, array[x]);
	}

	if (x == size)
		return (tree);

	return (NULL);
}
