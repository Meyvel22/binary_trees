#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 * Return: pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *l_rotate;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	l_rotate = tree->right;
	tree->right = l_rotate->left;
	if (l_rotate->left != NULL)
	{
		l_rotate->left->parent = tree;
	}
	l_rotate->left = tree;
	l_rotate->parent = tree->parent;
	tree->parent = l_rotate;
	return (l_rotate);
}
