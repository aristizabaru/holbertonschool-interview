#include "binary_trees.h"

/**
 * binary_tree_node - create a new binary tree node
 * @parent: pointer to the new binary tree's parent node
 * @value: integer to be save in the new binary tree node
 * 
 * Return: pointer to new binary tree node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = NULL;

	/* tree is empty */
	if (!parent)
	{
		new_node = create_node();
		new_node->n = value;
		return (new_node);
	}
	/* parent is valid */
	if (parent)
	{
		new_node = create_node();
		if (value)
			new_node->n = value;
		new_node->parent = parent;
		return (new_node);
	}
	return (NULL);
}

/**
 * create_node - create a new empty binary_tree_t
 * 
 * Return: pointer to new binary_tree_t
 */
binary_tree_t *create_node()
{
	binary_tree_t *new_node = NULL;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = 0;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
