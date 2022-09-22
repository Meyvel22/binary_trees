#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through binary tree usin level-order traversal
 * @tree:  pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * Return: If tree or func is NULL, do nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *list[1024];
	binary_tree_t *temp;
	int x = 0, y = 0;

	if (tree == NULL || func == NULL)
		return;
	for (x = 0; x < 1024; x++)
		list[x] = NULL;
	list[0] = (binary_tree_t *)tree;
	x = 0;
	while (list[x] != NULL)
	{
		temp = list[x];
		func(temp->n);
		if (temp->left != NULL)
		{
			y++;
			list[y] = temp->left;
		}
		if (temp->right != NULL)
		{
			y++;
			list[y] = temp->right;
		}
		x++;
	}
}
