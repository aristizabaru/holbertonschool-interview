#include "binary_trees.h"

/**
* heap_insert - inserts a value into a Max Binary Heap
* @root: root of the tree
* @value: the value of the new node
*
* Return: pointer to new node
*/
heap_t *heap_insert(heap_t **root, int value)
{
        int levels = 0, level, temp;
        heap_t *new_node = NULL;
        /* create first node if tree is NULL */
        if (!*root)
        {
                *root = binary_tree_node(NULL, value);
                return (*root);
        }
        /* get height */
        levels = tree_height(*root);
        /* insert node */
        for (level = 0; level <= levels; level++)
        {
                new_node = add_node(*root, level, value);
                if (new_node)
                        break;
        }
        /* swap nodes values*/
        while (new_node->parent && new_node->n > new_node->parent->n)
        {
                temp = new_node->parent->n;
                new_node->parent->n = new_node->n;
                new_node->n = temp;
                new_node = new_node->parent;
        }
        return (new_node);
}

/**
* tree_height - get the height of a binary sub-tree
* @tree: first node of the tree
*
* Return: height of the sub-tree
*/
int tree_height(heap_t *tree)
{
        int left_height, rigth_height;

        /* base case */
        if (!tree || is_leaf(tree) == 1)
                return (0);

        /* add levels */
        left_height = tree_height(tree->left) + 1;
        rigth_height = tree_height(tree->right) + 1;

        /* return biggest height */
        if (left_height >= rigth_height)
                return (left_height);
        return (rigth_height);
}

/**
* is_leaf - checks if a node is a leaf
* @node: node to check
*
* Return: 1 if is a leaf, 0 on failure
*/
int is_leaf(heap_t *node)
{
        if (!node->left && !node->right)
                return (1);
        return (0);
}

/**
* add_node - add a node
* @tree: pointer to tree
* @level: level of insertion
* @value: value of the new node
*
* Return: new node
*/
binary_tree_t *add_node(binary_tree_t *tree, int level, int value)
{
        binary_tree_t *left_node, *right_node;

        if (!tree)
                return (NULL);
        if (tree_depth(tree) == level)
        {
                if (is_leaf(tree))
                        return (tree->left = binary_tree_node(tree, value));
                if (tree->left && !tree->right)
                        return (tree->right = binary_tree_node(tree, value));
                return (NULL);
        }
        left_node = add_node(tree->left, level, value);
        if (!left_node)
                right_node = add_node(tree->right, level, value);
        else
                return (left_node);
        return (right_node);
}

/**
* tree_depth - get the depth of a node
* @tree: node to check
*
* Return: depth
*/
int tree_depth(const binary_tree_t *tree)
{
        int count = 0;

        while (tree->parent)
        {
                count++;
                tree = tree->parent;
        }
        return (count);
}
