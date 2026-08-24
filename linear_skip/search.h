#ifndef SEARCH_H
#define SEARCH_H

#include <stddef.h>

/**
 * struct skiplist_s - Node of a sorted skip list
 * @n: Integer stored in the node
 * @index: Position of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next express-lane node
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

skiplist_t *linear_skip(skiplist_t *list, int value);
skiplist_t *create_skiplist(int *array, size_t size);
void free_skiplist(skiplist_t *list);

#endif /* SEARCH_H */
