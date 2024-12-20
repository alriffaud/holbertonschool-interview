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
    left = [0] * n
    right = [0] * n
    water = 0

    left[0] = walls[0]
    for i in range(1, n):
        left[i] = max(left[i - 1], walls[i])

    right[n - 1] = walls[n - 1]
    for i in range(n - 2, -1, -1):
        right[i] = max(right[i + 1], walls[i])

    for i in range(n):
        water += min(left[i], right[i]) - walls[i]

    return water
