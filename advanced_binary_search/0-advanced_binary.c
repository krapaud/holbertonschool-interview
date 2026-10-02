#include <stdio.h>

#include "search_algos.h"

/**
 * print_search - Print the portion of the array being searched
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
 * advanced_search - Recursively find the first occurrence of a value
 * @array: Sorted array to search
 * @low: First index of the current range
 * @high: Last index of the current range
 * @value: Value to find
 *
 * Return: Index of the first occurrence, or -1
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
		return (advanced_search(array, low, middle - 1, value));
	return (advanced_search(array, middle + 1, high, value));
}

/**
 * advanced_binary - Search for the first occurrence of a value
 * @array: Sorted array to search
 * @size: Number of elements in the array
 * @value: Value to find
 *
 * Return: Index of the first occurrence, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);
	return (advanced_search(array, 0, size - 1, value));
}
