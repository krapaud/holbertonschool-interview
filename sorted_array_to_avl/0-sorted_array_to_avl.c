#include <stdlib.h>
#include "binary_trees.h"

/**
 * free_tree - Frees an AVL tree
 * @tree: Root of the tree to free
 */
static void free_tree(avl_t *tree)
{
	if (tree == NULL)
		return;
	free_tree(tree->left);
	free_tree(tree->right);
	free(tree);
}

/**
 * build_tree - Builds a balanced tree from part of an array
 * @array: Start of the current array section
 * @size: Number of values in the section
 * @parent: Parent of the node to create
 *
 * Return: Root of the created subtree, or NULL on failure
 */
static avl_t *build_tree(int *array, size_t size, avl_t *parent)
{
	avl_t *node;
	size_t middle;

	if (size == 0)
		return (NULL);

	middle = size / 2;
	node = malloc(sizeof(*node));
	if (node == NULL)
		return (NULL);

	node->n = array[middle];
	node->parent = parent;
	node->left = build_tree(array, middle, node);
	if (middle != 0 && node->left == NULL)
	{
		free_tree(node);
		return (NULL);
	}
	node->right = build_tree(array + middle + 1, size - middle - 1, node);
	if (size - middle - 1 != 0 && node->right == NULL)
	{
		free_tree(node);
		return (NULL);
	}

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (build_tree(array, size, NULL));
}
