#include "sandpiles.h"


/**
 * is_stable - Checks if a grid is stable
 * @grid: 3x3 grid to check
 *
 * Return: true if the grid is stable, false otherwise
 */
bool is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (false);
		}
	}
	return (true);
}

/**
 * topple - Topples an unstable sandpile
 * @grid: 3x3 grid to topple
 */
void topple(int grid[3][3])
{
	int i, j;
	int tmp[3][3] = {0};

	/* Topple each cell that is greater than 3 */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				tmp[i][j] -= 4;
				/* Topple up */
				if (i - 1 >= 0)
					tmp[i - 1][j] += 1;
				/* Topple down */
				if (i + 1 < 3)
					tmp[i + 1][j] += 1;
				/* Topple left */
				if (j - 1 >= 0)
					tmp[i][j - 1] += 1;
				/* Topple right */
				if (j + 1 < 3)
					tmp[i][j + 1] += 1;
			}
		}
	}

	/* Apply the topple changes to the grid */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] += tmp[i][j];
		}
	}
}

/**
 * print_grid - Prints a 3x3 grid
 * @grid: 3x3 grid to print
 */
void print_grid(int grid[3][3])
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
 * sandpiles_sum - Computes the sum of two sandpiles and stabilizes the result
 * @grid1: First 3x3 grid
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	/* Add the two grids */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	/* Stabilize grid1 if necessary */
	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
