#include <stdio.h>

#include "sort.h"

/**
 * print_array - Print an array of integers
 * @array: Array to print
 * @size: Number of elements in the array
 */
void print_array(const int *array, size_t size)
{
	size_t index;

	for (index = 0; index < size; index++)
	{
		if (index > 0)
			printf(", ");
		printf("%d", array[index]);
	}
	printf("\n");
}
