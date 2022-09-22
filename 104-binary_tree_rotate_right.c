#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *r_rotate;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	r_rotate = tree->left;
	tree->left = r_rotate->right;
	if (r_rotate->right != NULL)
	{
		r_rotate->right->parent = tree;
	}
	r_rotate->right = tree;
	r_rotate->parent = tree->parent;
	tree->parent = r_rotate;
	return (r_rotate);
}
