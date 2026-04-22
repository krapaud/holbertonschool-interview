#!/usr/bin/python3

def minOperations(n):
    operations = 0
    division = 2

    while (n > 1):
        while n % division == 0:
            operations += division
            n //= division
        division += 1
    return operations
