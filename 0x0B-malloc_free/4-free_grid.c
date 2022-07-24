#include "main.h"
#include <stdlib.h>

/**
  * free_grid - ...
  * @grid: ...
  * @height: ...
  *
  * Return: ...
  */
void free_grid(int **grid, int height)
{
	int i, j;

	for (i = 0; i < height; i++)
	{
		if (grid[i] == NULL)
		{
			for (j = i; j >= 0; j--)
			{
				free(grid[j]);
			}

			free(grid);
		}
	}
}
