#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/**
 * struct binary_tree_s - Nœud d’un arbre binaire.
 * @n: Valeur entière stockée dans le nœud.
 * @parent: Pointeur vers le parent du nœud.
 * @left: Pointeur vers le fils gauche.
 * @right: Pointeur vers le fils droit.
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
int heap_extract(heap_t **root);

#endif /* BINARY_TREES_H */
