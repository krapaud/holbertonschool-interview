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
	int *tab;
	size_t i = 0;

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

	/* j'alloue un tableau de la bonne taille pour stocker les valeurs */
	tab = malloc(sizeof(int) * len);
	if (tab == NULL)
		return (0);

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
			free(tab);
			return (0);
		}
	}
	free(tab);
	return (1);
}
