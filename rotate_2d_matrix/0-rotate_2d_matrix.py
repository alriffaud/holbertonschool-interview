#!/usr/bin/python3
"""
This module defines a function that rotates a given n x n 2D matrix 90 degrees.
"""


def rotate_2d_matrix(matrix):
    """
    This function rotates a given n x n 2D matrix 90 degrees clockwise in place
    Args:
        matrix (list of list of int): The 2D matrix to rotate.
    Returns:
        None: The matrix is modified in place.
    """
    n = len(matrix)

    # Step 1: Transpose the matrix
    for i in range(n):
        for j in range(i + 1, n):
            # Swap elements matrix[i][j] and matrix[j][i]
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Step 2: Reverse each row
    for row in matrix:
        row.reverse()
