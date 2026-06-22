#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle
 * @list: Pointer to the head of the list
 *
 * Return: 1 if there is a cycle, 0 otherwise
 */
int check_cycle(listint_t *list)
{
	listint_t *lievre;
	listint_t *tortue;

	lievre = list;
	tortue = list;

	while (lievre != NULL && lievre->next != NULL)
	{
		tortue = tortue->next;
		lievre = lievre->next->next;

		if (tortue == lievre)
			return (1);
	}
	return (0);
}
