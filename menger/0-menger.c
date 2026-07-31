#include <math.h>
#include <stdio.h>
#include "menger.h"

/**
 * is_space - Checks if a cell should be empty or filled
 * @row: Row index of the cell
 * @col: Column index of the cell
 * @level: Level of the Menger sponge
 *
 * Return: 1 if the cell is empty (space), 0 if it should be filled (#)
 */
static int is_space(int row, int col, int level)
{
	int k;
	int size;

	/* je vérifie à chaque niveau de subdivision */
	for (k = 0; k < level; k++)
	{
		/* la taille d'un bloc à ce niveau */
		size = (int)pow(3, k);

		/* si la case tombe dans le centre d'un bloc 3x3 à ce niveau */
		if ((row / size) % 3 == 1 && (col / size) % 3 == 1)
			return (1);
	}
	return (0);
}

/**
 * menger - Draws a 2D Menger Sponge
 * @level: Level of the Menger Sponge to draw
 */
void menger(int level)
{
	int size;
	int row, col;

	/* si le niveau est negatif on ne fait rien */
	if (level < 0)
		return;

	/* la taille totale de la grille = 3^level */
	size = (int)pow(3, level);

	/* je parcours chaque ligne */
	for (row = 0; row < size; row++)
	{
		/* je parcours chaque colonne */
		for (col = 0; col < size; col++)
		{
			/* si la case doit etre vide, j'affiche un espace */
			if (is_space(row, col, level))
				putchar(' ');
			else
				putchar('#');
		}
		putchar('\n');
	}
}
