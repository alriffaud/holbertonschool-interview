#!/usr/bin/python3
""" This module solves the N queens puzzle """
import sys


def is_safe(board, row, col):
    """ Check if a queen can be placed on board[row][col] """
    for i in range(row):
        # Check the same column
        if board[i] == col:
            return False
        # Check left diagonal
        if board[i] - i == col - row:
            return False
        # Check right diagonal
        if board[i] + i == col + row:
            return False
    return True


def solve_nqueens(N, row, board, solutions):
    """
    Solves the N Queens problem using backtracking.
    """
    if row == N:
        # Generate a solution in the expected format
        solution = [[i, board[i]] for i in range(N)]
        solutions.append(solution)
        return

    for col in range(N):
        if is_safe(board, row, col):
            board[row] = col
            solve_nqueens(N, row + 1, board, solutions)
            # There is no need to "undo" since we overwrite at each iteration.


def main():
    """
    Argument handling and main program execution.
    """
    # Check the number of arguments
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    # Validate that N is an integer
    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    # Validate that N >= 4
    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    # Solving the N queens problem
    solutions = []
    # Initialize the board with -1 (no queen)
    board = [-1] * N
    solve_nqueens(N, 0, board, solutions)

    # Print the solutions
    for solution in solutions:
        print(solution)


if __name__ == "__main__":
    main()
