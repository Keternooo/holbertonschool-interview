#!/usr/bin/python3
"""
Module to determine the minimum number of operations to reach a target number
"""

def minOperations(n):
    if n <= 1:
        return 0

    operations = 0
    factor = 2
    while factor * factor <= n:
        while n % factor == 0:
            operations += factor
            n = n // factor
        factor += 1
    if n > 1:
        operations += n

    return operations
