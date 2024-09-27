#ifndef _sandpiles_h
#define _sandpiles_h

#include <stdbool.h>
#include <stdio.h>

/* Function prototypes */
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
static void print_grid(int grid[3][3]);
bool is_stable(int grid[3][3]);
void topple(int grid[3][3]);


#endif
