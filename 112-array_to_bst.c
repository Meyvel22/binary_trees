#include "binary_trees.h"

/**
 * array_to_bst - function that builds a Binary Search Tree from an array
 * @array: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 * Return: pointer to the root node of the created BST, or NULL on failure
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree;
	size_t x;

	tree = NULL;

	for (x = 0; x < size; x++)
	{
		bst_insert(&tree, array[x]);
	}

	if (x == size)
		return (tree);

	return (NULL);
}
