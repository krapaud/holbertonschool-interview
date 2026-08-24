#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../search.h"

void free_skiplist(skiplist_t *list);

skiplist_t *create_skiplist(int *array, size_t size)
{
	skiplist_t *head = NULL;
	skiplist_t *tail = NULL;
	skiplist_t *node;
	skiplist_t *express;
	size_t i;
	size_t step;

	if (array == NULL || size == 0)
		return (NULL);
	step = (size_t)sqrt((double)size);
	if (step == 0)
		step = 1;
	for (i = 0; i < size; i++)
	{
		node = malloc(sizeof(*node));
		if (node == NULL)
		{
			free_skiplist(head);
			return (NULL);
		}
		node->n = array[i];
		node->index = i;
		node->next = NULL;
		node->express = NULL;
		if (head == NULL)
			head = node;
		else
			tail->next = node;
		tail = node;
	}
	for (i = 0; i + step < size; i += step)
	{
		node = head;
		express = head;
		while (node != NULL && node->index < i)
			node = node->next;
		while (express != NULL && express->index < i + step)
			express = express->next;
		if (node != NULL)
			node->express = express;
	}
	return (head);
}

void print_skiplist(const skiplist_t *list)
{
	const skiplist_t *current;

	printf("List :\n");
	for (current = list; current != NULL; current = current->next)
		printf("Index[%lu] = [%d]\n", current->index, current->n);
	printf("\nExpress lane :\n");
	for (current = list; current != NULL; current = current->express)
		printf("Index[%lu] = [%d]\n", current->index, current->n);
	printf("\n");
}

void free_skiplist(skiplist_t *list)
{
	skiplist_t *next;

	while (list != NULL)
	{
		next = list->next;
		free(list);
		list = next;
	}
}
