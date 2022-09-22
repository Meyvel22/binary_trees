#include "binary_trees.h"

/**
 * recursive_height - measures the height of a binary tree
 * @tree: the root of the tree
 * Return: height of the binary tree
 */

size_t recursive_height(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (tree == NULL)
		return (0);

	left = recursive_height(tree->left);
	right = recursive_height(tree->right);

	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * binary_tree_is_leaf - a function that checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0. if node is NULL return 0
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
 * check_parent - checks if node is lower/higher than its grand parent
 * @tree: the actual node
 * Return: 1 if actual node is valid, 0 otherwise
 */

int check_parent(const binary_tree_t *tree)
{
	const binary_tree_t *pa_rent;
	const binary_tree_t *grand_pa_rent;

	if (tree == NULL || tree->parent == NULL || tree->parent->parent == NULL)
		return (1);

	pa_rent = tree->parent;
	grand_pa_rent = pa_rent->parent;

	while (pa_rent && grand_pa_rent)
	{
		if (pa_rent->n < grand_pa_rent->n && tree->n >= grand_pa_rent->n)
			return (0);

		if (pa_rent->n > grand_pa_rent->n && tree->n <= grand_pa_rent->n)
			return (0);

		pa_rent = pa_rent->parent;
		grand_pa_rent = pa_rent->parent;
	}

	return (1);
}

/**
 * check_is_bst - checks if binary tree is a BST
 * @tree: the root of the tree
 * Return: 1 if tree is a BST, 0 otherwise
 */

int check_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (binary_tree_is_leaf(tree))
		return (1);

	if (tree->left && tree->left->n >= tree->n)
		return (0);

	if (tree->right && tree->right->n <= tree->n)
		return (0);

	if (!check_parent(tree->left) || !check_parent(tree->right))
		return (0);

	return (check_is_bst(tree->left) && check_is_bst(tree->right));
}


/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise.
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree && check_is_bst(tree) &&
	    (recursive_height(tree->left) - recursive_height(tree->right) == 0))
	{
		return (1);
	}

	return (0);
}
