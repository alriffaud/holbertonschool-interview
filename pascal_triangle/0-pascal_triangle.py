#!/usr/bin/python3
""" This module defines the pascal_triangle function """


def pascal_triangle(n):
    """
    This function returns a list of lists of integers representing the
    Pascal's triangle.
    Args:
        n (int): The number of rows in the triangle.
    Returns:
        list: A list of lists of integers.
    """
    if n <= 0:
        return []
    p_tri = [[1]]
    i = 2
    while i <= n:
        aux = [1] * i
        for j in range(1, i - 1):
            aux[j] = p_tri[i - 2][j - 1] + p_tri[i - 2][j]
        p_tri.append(aux)
        i += 1
    return p_tri
