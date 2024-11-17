#include <iostream>
#include <cmath>
#include "menger.h"


/**
 * menger - this function draws a 2D Menger Sponge
 * @level: is the level of the Menger Sponge to draw
 */
void menger(int level)
{
	int size = pow(3, level);

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			char c = '#';

			for (int k = 1; k < size; k *= 3)
			{
				if ((i / k) % 3 == 1 && (j / k) % 3 == 1)
				{
					c = ' ';
					break;
				}
			}
			printf("%c", c);
		}
		printf("\n");
	}
}
