#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: a pointer to the node to insert the left-child in
 * @value: the valuse to store in the new node
 * Return: pointer to the created node of NULL on failure of if parent is NULL
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *l_node;

	if (parent == NULL)
		return (NULL);

	l_node = binary_tree_node(parent, value);
	if (l_node == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		l_node->left = parent->left;
		parent->left->parent = l_node;
	}
	parent->left = l_node;

	return (l_node);
}
