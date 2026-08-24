#include <stdio.h>
#include "search.h"

/**
 * print_checked - Prints a checked node
 * @node: Node that was checked
 */
static void print_checked(skiplist_t *node)
{
	printf("Value checked at index [%lu] = [%d]\n",
	       node->index, node->n);
}

/**
 * search_range - Searches between two nodes
 * @start: First node to check
 * @end: Last boundary node
 * @value: Value to search for
 *
 * Return: First matching node, or NULL
 */
static skiplist_t *search_range(skiplist_t *start, skiplist_t *end,
				int value)
{
	skiplist_t *current;

	current = start;
	while (current != NULL &&
	       (current != end || end->next == NULL))
	{
		print_checked(current);
		if (current->n == value)
			return (current);
		if (current->n > value)
			return (NULL);
		current = current->next;
	}
	if (end != NULL && end->n == value)
	{
		print_checked(end);
		return (end);
	}
	return (NULL);
}

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @list: Head of the skip list
 * @value: Value to search for
 *
 * Return: Node containing value, or NULL if value is not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *start, *end, *current;

	if (list == NULL)
		return (NULL);
	start = list;
	current = list;
	while (current->express != NULL)
	{
		current = current->express;
		print_checked(current);
		if (current->n >= value)
			break;
		start = current;
	}
	end = current;
	if (end == start && start->n < value)
	{
		while (end->next != NULL)
			end = end->next;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
	       start->index, end->index);
	return (search_range(start, end, value));
}
