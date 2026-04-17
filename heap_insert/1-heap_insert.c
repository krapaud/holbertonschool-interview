#include <stdlib.h>
#include "binary_trees.h"

/**
 * find_insert_parent - Trouve le premier nœud avec un enfant manquant
 * en parcourant l'arbre niveau par niveau (BFS)
 * @root: Pointeur vers la racine
 *
 * Return: Le nœud parent où insérer le nouveau nœud
 */
static heap_t *find_insert_parent(heap_t *root)
{
	heap_t *queue[1024];
	int front = 0, back = 0;
	heap_t *node;

	/* On met la racine dans la file d'attente pour commencer */
	queue[back++] = root;

	while (front < back)
	{
		/* On prend le prochain nœud à examiner */
		node = queue[front++];

		/* Si ce nœud a un enfant manquant, c'est ici qu'on insère */
		if (node->left == NULL || node->right == NULL)
			return (node);

		/* Sinon on ajoute ses enfants dans la file pour les examiner après */
		queue[back++] = node->left;
		queue[back++] = node->right;
	}
	return (NULL);
}

/**
 * bubble_up - Remonte un nœud tant qu'il est plus grand que son parent
 * @node: Le nœud à remonter
 *
 * Return: Le nœud à sa position finale
 */
static heap_t *bubble_up(heap_t *node)
{
	int tmp;

	while (node->parent && node->n > node->parent->n)
	{
		/* On échange les valeurs avec le parent */
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;

		/* On monte d'un niveau */
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;
	heap_t *parent;

	/* Étape 1 : créer le nouveau nœud */
	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	/* Étape 2 : si l'arbre est vide, le nouveau nœud devient la racine */
	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	/* Étape 3 : trouver où insérer le nœud */
	parent = find_insert_parent(*root);

	/* Étape 4 : l'attacher à gauche ou à droite selon ce qui est libre */
	if (parent->left == NULL)
		parent->left = new_node;
	else
		parent->right = new_node;
	new_node->parent = parent;

	/* Étape 5 : le remonter si sa valeur est plus grande que son parent */
	return (bubble_up(new_node));
}
