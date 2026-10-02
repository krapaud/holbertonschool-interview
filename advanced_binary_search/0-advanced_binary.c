#include <stdio.h>

#include "search_algos.h"

/**
 * print_search - J'affiche la partie du tableau que je recherche
 * @array: Array to print
 * @low: First index to print
 * @high: Last index to print
 */
static void print_search(int *array, size_t low, size_t high)
{
	size_t index;

	printf("Searching in array: ");
	for (index = low; index <= high; index++)
	{
		if (index > low)
			printf(", ");
		printf("%d", array[index]);
	}
	printf("\n");
}

/**
 * advanced_search - Je cherche récursivement la première occurrence
 * @array: Sorted array to search
 * @low: First index of the current range
 * @high: Last index of the current range
 * @value: Value to find
 *
 * Return: L'indice de la première occurrence, ou -1
 */
static int advanced_search(int *array, size_t low, size_t high, int value)
{
	size_t middle;

	if (low > high)
		return (-1);

	print_search(array, low, high);
	middle = low + (high - low) / 2;

	if (array[middle] == value)
	{
		if (middle == low)
			return ((int)middle);
		return (advanced_search(array, low, middle, value));
	}
	if (array[middle] > value)
	{
		if (middle == low)
			return (-1);
		return (advanced_search(array, low, middle, value));
	}
	return (advanced_search(array, middle + 1, high, value));
}

/**
 * advanced_binary - Je cherche la première occurrence d'une valeur
 * @array: Sorted array to search
 * @size: Number of elements in the array
 * @value: Value to find
 *
 * Return: L'indice de la première occurrence, ou -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (advanced_search(array, 0, size - 1, value));
}
