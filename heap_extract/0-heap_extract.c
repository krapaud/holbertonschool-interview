#include <stdlib.h>

#include "binary_trees.h"

/**
 * heap_size - Je compte récursivement les nœuds du tas.
 * @node: Nœud à partir duquel je compte.
 *
 * Return: Nombre de nœuds dans le sous-arbre.
 */
static size_t heap_size(const heap_t *node)
{
	if (node == NULL)
		return (0);
	return (1 + heap_size(node->left) + heap_size(node->right));
}

/**
 * sift_down - Je rétablis la propriété du tas maximal depuis la racine.
 * @node: Racine du sous-arbre à réorganiser.
 */
static void sift_down(heap_t *node)
{
	heap_t *largest;
	int temporary_value;

	while (node != NULL && node->left != NULL)
	{
		largest = node->left;
		if (node->right != NULL && node->right->n > largest->n)
			largest = node->right;
		if (node->n >= largest->n)
			return;

		temporary_value = node->n;
		node->n = largest->n;
		largest->n = temporary_value;
		node = largest;
	}
}

/**
 * get_last_node - Je récupère le dernier nœud en ordre de niveau.
 * @root: Racine du tas.
 * @count: Nombre de nœuds dans le tas.
 *
 * Return: Dernier nœud du tas, ou NULL s’il est introuvable.
 */
static heap_t *get_last_node(heap_t *root, size_t count)
{
	size_t path, mask;

	path = count;
	mask = 1;
	while (mask <= path / 2)
		mask <<= 1;
	mask >>= 1;
	while (mask > 0 && root != NULL)
	{
		root = (path & mask) ? root->right : root->left;
		mask >>= 1;
	}
	return (root);
}

/**
 * install_last_as_root - Je remplace la racine par le dernier nœud.
 * @root: Adresse de la racine du tas.
 * @last: Dernier nœud en ordre de niveau.
 *
 * Return: 1 si le remplacement réussit, sinon 0.
 */
static int install_last_as_root(heap_t **root, heap_t *last)
{
	heap_t *old_root, *parent, *old_left, *old_right;

	old_root = *root;
	parent = last->parent;
	if (parent == NULL)
		return (0);
	if (parent->left == last)
		parent->left = NULL;
	else if (parent->right == last)
		parent->right = NULL;
	else
		return (0);

	old_left = old_root->left;
	old_right = old_root->right;
	last->parent = NULL;
	last->left = (old_left == last) ? NULL : old_left;
	last->right = (old_right == last) ? NULL : old_right;
	if (last->left != NULL)
		last->left->parent = last;
	if (last->right != NULL)
		last->right->parent = last;

	free(old_root);
	*root = last;
	sift_down(last);
	return (1);
}

/**
 * heap_extract - J’extrais la valeur maximale du tas.
 * @root: Double pointeur vers la racine du tas.
 *
 * Return: Valeur extraite, ou 0 si le tas est vide ou invalide.
 */
int heap_extract(heap_t **root)
{
	heap_t *old_root, *last;
	size_t count;
	int value;

	if (root == NULL || *root == NULL)
		return (0);

	old_root = *root;
	value = old_root->n;
	count = heap_size(old_root);
	if (count == 1)
	{
		free(old_root);
		*root = NULL;
		return (value);
	}

	last = get_last_node(old_root, count);
	if (last == NULL || !install_last_as_root(root, last))
		return (0);
	return (value);
}
