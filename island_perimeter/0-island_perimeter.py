#!/usr/bin/python3
"""
This module contains a function that returns the perimeter of the island
described in grid.
"""


def island_perimeter(grid):
    """
    This function returns the perimeter of the island described in grid.
    Args:
        grid: a list of list of integers
    Returns:
        perimeter: an integer
    """
    perimeter = 0
    m = len(grid)
    n = len(grid[0])
    for row in range(m):
        for col in range(n):
            if grid[row][col] == 1:
                # Check each direction
                if row == 0 or grid[row - 1][col] == 0:  # Up
                    perimeter += 1
                if row == m - 1 or grid[row + 1][col] == 0:  # Down
                    perimeter += 1
                if col == 0 or grid[row][col - 1] == 0:  # Left
                    perimeter += 1
                if col == n - 1 or grid[row][col + 1] == 0:  # Right
                    perimeter += 1
    return perimeter
