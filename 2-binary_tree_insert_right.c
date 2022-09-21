#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: a pointer to the node to insert the right-child in
 * @value: the value to store in the new node
 * Return: pointer to the created node or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *r_node;

	if (parent == NULL)
		return (NULL);
	r_node = binary_tree_node(parent, value);
	if (r_node == NULL)
		return (NULL);
	r_node->right = parent->right;
	if (r_node->right != NULL)
	{
		r_node->right->parent = r_node;
	}
	parent->right = r_node;
	return (r_node);
}
