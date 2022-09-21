#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: the pointer to the parent node of the node to create
 * @value: the value to put the new node
 * Return: a pointer to the new node or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_p;

	new_p = malloc(sizeof(binary_tree_t));
	if (new_p == NULL)
		return (NULL);

	new_p->parent = parent;
	new_p->n = value;
	new_p->left = NULL;
	new_p->right = NULL;

	return (new_p);
}
