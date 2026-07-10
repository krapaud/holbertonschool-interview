#include <stddef.h>
#include "slide_line.h"

/**
 * slide_left - Slides and merges a line to the left
 * @line: Pointer to the array
 * @size: Number of elements
 */
static void slide_left(int *line, size_t size)
{
	size_t i, pos;

	/* compression 1 : enlever les zeros */
	pos = 0;
	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[pos] = line[i];
			if (pos != i)
				line[i] = 0;
			pos++;
		}
	}
	/* fusion : combiner les identiques adjacents */
	for (i = 0; i + 1 < size; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
			i++;
		}
	}
	/* compression 2 : remettre les zeros a droite */
	pos = 0;
	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			line[pos] = line[i];
			if (pos != i)
				line[i] = 0;
			pos++;
		}
	}
}

/**
 * slide_right - Slides and merges a line to the right
 * @line: Pointer to the array
 * @size: Number of elements
 */
static void slide_right(int *line, size_t size)
{
	size_t i, pos;

	/* compression 1 : pousser les non-zeros vers la droite */
	pos = size;
	for (i = size; i > 0; i--)
	{
		if (line[i - 1] != 0)
		{
			pos--;
			line[pos] = line[i - 1];
			if (pos != i - 1)
				line[i - 1] = 0;
		}
	}
	for (i = 0; i < pos; i++)
		line[i] = 0;
	/* fusion : combiner les identiques, de droite a gauche */
	for (i = size; i > 1; i--)
	{
		if (line[i - 1] != 0 && line[i - 1] == line[i - 2])
		{
			line[i - 1] *= 2;
			line[i - 2] = 0;
			i--;
		}
	}
	/* compression 2 : remettre les zeros a gauche */
	pos = size;
	for (i = size; i > 0; i--)
	{
		if (line[i - 1] != 0)
		{
			pos--;
			line[pos] = line[i - 1];
			if (pos != i - 1)
				line[i - 1] = 0;
		}
	}
	for (i = 0; i < pos; i++)
		line[i] = 0;
}

/**
 * slide_line - Slides and merges an array of integers
 * @line: Pointer to the array
 * @size: Number of elements
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		return (1);
	}
	if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		return (1);
	}
	return (0);
}
