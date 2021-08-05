# 0x02. Heap Insert

## About

This is an educational project that explore the **Heap Insert** interview problem to better prepare candidates for this assignment in the future.

_This problem is solved using C programming language_

## Table of contents

- [Requirements](#requirements)
- [Files](#files)

## Requirements

- gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic

## Files

### Before start

Please use the following data structures and types for binary trees. Don’t forget to include them in your header file.

**Basic Binary Tree**

```
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};
```

**Max Binary Heap**

```
typedef struct binary_tree_s heap_t;
```

**Print function**
To match the examples in the tasks, you are given [this function](https://github.com/holbertonschool/0x1C.c)

### 0. New node

**[0-binary_tree_node.c](0-binary_tree_node.c)**

Write a function that creates a binary tree node:

- Prototype: `binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);`
- `parent` is a pointer to the parent node of the node to create
- `value` is the value to put in the new node
- When created, a node does not have any children
- Your function must return a pointer to the new node, or `NULL` on failure

```
alex@/tmp/binary_trees$ cat 0-main.c
#include <stdlib.h>
#include "binary_trees.h"

/**
 * _binary_tree_delete - Deallocate a binary tree
 *
 * @tree: Pointer to the root of the tree to delete
 */
static void _binary_tree_delete(binary_tree_t *tree)
{
    if (tree)
    {
        _binary_tree_delete(tree->left);
        _binary_tree_delete(tree->right);
        free(tree);
    }
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);

    root->left = binary_tree_node(root, 12);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 16);

    root->right = binary_tree_node(root, 402);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);

    binary_tree_print(root);
    _binary_tree_delete(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
alex@/tmp/binary_trees$ ./0-node
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (016)     (256)     (512)
alex@/tmp/binary_trees$
```

### 1. Heap - Insert

**[1-heap_insert.c](1-heap_insert.c)**
**[0-binary_tree_node.c](0-binary_tree_node.c)**

Write a function that inserts a value into a Max Binary Heap:

- Prototype: `heap_t *heap_insert(heap_t **root, int value);`
- `root` is a double pointer to the root node of the Heap
- `value` is the value to store in the node to be inserted
- Your function must return a pointer to the inserted node, or `NULL` on failure
- If the address stored in `root` is `NULL`, the created node must become the root node.
- You have to respect a `Max Heap` ordering
- You are allowed to have up to `6` functions in your file

Your file `0-binary_tree_node.c` will be compiled during the correction

```
alex@/tmp/binary_trees$ cat 0-main.c
#include <stdlib.h>
#include "binary_trees.h"

/**
 * _binary_tree_delete - Deallocate a binary tree
 *
 * @tree: Pointer to the root of the tree to delete
 */
static void _binary_tree_delete(binary_tree_t *tree)
{
    if (tree)
    {
        _binary_tree_delete(tree->left);
        _binary_tree_delete(tree->right);
        free(tree);
    }
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root;

    root = binary_tree_node(NULL, 98);

    root->left = binary_tree_node(root, 12);
    root->left->left = binary_tree_node(root->left, 6);
    root->left->right = binary_tree_node(root->left, 16);

    root->right = binary_tree_node(root, 402);
    root->right->left = binary_tree_node(root->right, 256);
    root->right->right = binary_tree_node(root->right, 512);

    binary_tree_print(root);
    _binary_tree_delete(root);
    return (0);
}
alex@/tmp/binary_trees$ gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_node.c -o 0-node
alex@/tmp/binary_trees$ ./0-node
       .-------(098)-------.
  .--(012)--.         .--(402)--.
(006)     (016)     (256)     (512)
alex@/tmp/binary_trees$
```
