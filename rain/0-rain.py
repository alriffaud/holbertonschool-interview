#!/usr/bin/python3
""" This module defines the rain function. """


def rain(walls):
    """
    Calculate how much water will be retained after it rains.
    Args:
        walls: A list of non-negative integers.
    Returns:
        The total amount of rainwater retained.
    """
    if not walls:
        return 0

    n = len(walls)

    i = 0
    while walls[i] == 0 and i < n:
        i += 1

    if i == n:
        return 0

    left = walls[i]
    right = 0
    empty = 0
    total = 0

    for j in range(i + 1, n):
        if walls[j] == 0:
            empty += 1
        else:
            right = walls[j]
            minimo = min(left, right)
            total += minimo * empty
            # Restart values
            left = right
            empty = 0
            right = 0

    return total
