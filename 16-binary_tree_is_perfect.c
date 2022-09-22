#include "binary_trees.h"

/**
 * tree_is_perfect - function that checks if a tree is perfect
 * it has to be the same quantity of levels in left as right, and also
 * each node has to have 2 nodes or none
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */
int tree_is_perfect(const binary_tree_t *tree)
{
	int l_perfect = 0;
	int r_perfect = 0;

	if (tree->left && tree->right)
	{
		l_perfect = 1 + tree_is_perfect(tree->left);
		r_perfect = 1 + tree_is_perfect(tree->right);
		if (r_perfect == l_perfect && r_perfect != 0 && l_perfect != 0)
			return (r_perfect);
		return (0);
	}
	else if (!tree->left && !tree->right)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_is_perfect - unction that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: If tree is NULL, your function must return 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int result = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		result = tree_is_perfect(tree);
		if (result != 0)
			return (1);
		return (0);
	}
}
