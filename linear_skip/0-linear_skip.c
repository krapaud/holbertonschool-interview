#include <stdio.h>
#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Head of the skip list
 * @value: Value to search for
 *
 * Return: Node containing value, or NULL if value is not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current;
	skiplist_t *start;
	skiplist_t *end;

	if (list == NULL)
		return (NULL);

	start = list;
	current = list;
	while (current != NULL && current->express != NULL)
	{
		current = current->express;
		printf("Value checked at index [%lu] = [%d]\n",
		       current->index, current->n);
		if (current->n >= value)
			break;
		start = current;
	}

	if (current == NULL)
		end = start;
	else if (current->n >= value)
		end = current;
	else
		end = current;

	if (end == start && start->n < value)
	{
		while (end->next != NULL)
			end = end->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
	       start->index, end->index);

	current = start;
	while (current != NULL &&
	       (current != end || end->next == NULL))
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       current->index, current->n);
		if (current->n == value)
			return (current);
		if (current->n > value)
			return (NULL);
		current = current->next;
	}
	if (end != NULL && end->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       end->index, end->n);
		return (end);
	}

	return (NULL);
}
