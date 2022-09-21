#include "binary_trees.h"

/**
 * binary_tree_is_leaf - a function that checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0. If node is NULL, return 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, your function must return 0
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height;
	size_t r_height;

	if (tree == NULL || binary_tree_is_leaf(tree))
		return (0);
	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);
	if (r_height <= l_height)
		return (l_height + 1);

	return (r_height + 1);

}
