#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * is_stable - Checks if a grid is stable (no cell > 3)
 * @grid: 3x3 grid
 *
 * Return: 1 if stable, 0 otherwise
 */
static int is_stable(int grid[3][3])
{
    int i, j;

	for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
            {
                return 0;
            }
        }
    }
    return 1;
}

/**
 * topple - Topples all unstable cells simultaneously
 * @grid: 3x3 grid
 */
static void topple(int grid[3][3])
{
    int tmp[3][3] = {0};  /* grille des modifications */
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
            {
                tmp[i][j] -= 4;         /* la case perd 4 */
                /* ses voisins gagnent 1, si ils existent */
                if (i > 0) tmp[i-1][j] += 1;  /* haut */
                if (i < 2) tmp[i+1][j] += 1;  /* bas */
                if (j > 0) tmp[i][j-1] += 1;  /* gauche */
                if (j < 2) tmp[i][j+1] += 1;  /* droite */
            }
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid[i][j] += tmp[i][j];
        }
    }
}

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i ,j;

	for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }
    while (!is_stable(grid1))
    {
        printf("=\n");
        print_grid(grid1);
        topple(grid1);
    }
}
