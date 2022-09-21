#include "binary_trees.h"

/**
 * binary_tree_height_2 - function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: If tree is NULL, your function must return 0
 */

size_t binary_tree_height_2(const binary_tree_t *tree)
{
	size_t l_height;
	size_t r_height;

	if (tree == NULL)
		return (0);

	l_height = binary_tree_height_2(tree->left);
	r_height = binary_tree_height_2(tree->right);
	if (r_height <= l_height)
		return (l_height + 1);

	return (r_height + 1);

}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: If tree is NULL, return 0
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int b_left;
	int b_right;

	if (tree == NULL)
		return (0);

	b_left = binary_tree_height_2(tree->left);
	b_right = binary_tree_height_2(tree->right);
	return (b_left - b_right);
}
