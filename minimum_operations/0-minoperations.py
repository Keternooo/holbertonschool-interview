#!/usr/bin/python3
"""
Module to determine the minimum number of operations to reach a target number
"""

def minOperations(n):
    if n <= 1:
       return 0
    operations = 0
    aa = 'h'
    oldaa = ''
    while len(aa) < n:
        if len(aa + oldaa) > n:
            operations += 1
            break
        oldaa = aa
        aa += oldaa
        operations += 2
    return operations

