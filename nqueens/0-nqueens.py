#!/usr/bin/python3
"""Module that solves the N queens problem using backtracking"""
import sys


def is_safe(queens, row, col):
    """Check if placing a queen at (row, col) is safe.

    Args:
        queens (list): List of [row, col] positions of already placed queens
        row (int): Row to check
        col (int): Column to check

    Return:
        True if safe, False otherwise
    """
    for q in queens:
        # je verifie si la colonne est déjà prise
        if q[1] == col:
            return False
        # je verifie les diagonales
        if abs(q[0] - row) == abs(q[1] - col):
            return False
    return True


def solve(n, row, queens):
    """Recursively place queens row by row using backtracking.

    Args:
        n (int): Size of the board
        row (int): Current row to fill
        queens (list): Queens placed so far
    """
    # si toutes les reines sont placées, on affiche la solution
    if row == n:
        print(queens)
        return

    # j'essaie chaque colonne pour la ligne courante
    for col in range(n):
        if is_safe(queens, row, col):
            # je place la reine et je passe à la ligne suivante
            solve(n, row + 1, queens + [[row, col]])


if __name__ == "__main__":
    # je verifie le nombre d'arguments
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    # je verifie que N est un entier
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    # je verifie que N est au moins 4
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solve(n, 0, [])
