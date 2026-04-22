#!/usr/bin/python3
"""Module that calculates the minimum number of operations to reach n
H chars"""


def minOperations(n):
    """Calculate the fewest operations to get exactly n H characters.

    Uses Copy All and Paste operations starting from a single H.
    The minimum number of operations equals the sum of prime factors of n.

    Args:
        n (int): Target number of H characters

    Returns:
        int: Minimum number of operations, or 0 if impossible
    """
    if n <= 1:
        return 0
    operations = 0
    division = 2

    while n > 1:
        while n % division == 0:
            operations += division
            """Need to input two / for have an integer and not a float"""
            n //= division
        division += 1
    return operations
