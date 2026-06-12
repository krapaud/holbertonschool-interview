#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Double pointer to the head of the list
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	size_t len = 0;
	listint_t *current = *head;
	size_t i = 0;
	int tab[4096];

	/* si la liste est vide c'est un palindrome */
	if (*head == NULL)
	{
		return (1);
	}

	/* je compte le nombre de noeuds dans la liste */
	while (current != NULL)
	{
		len++;
		current = current->next;
	}

	/* je copie les valeurs de la liste dans le tableau */
	current = *head;
	while (current != NULL)
	{
		tab[i] = current->n;
		i++;
		current = current->next;
	}

	/* je compare le debut et la fin du tableau, effet miroir */
	for (i = 0; i < len / 2; i++)
	{
		if (tab[i] != tab[len - 1 - i])
		{
			return (0);
		}
	}
	return (1);
}
