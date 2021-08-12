#!/usr/bin/python3
"""docstring"""


def minOperations(n):
    """docstring"""
    if not isinstance(n, int) or n <= 1:
        return 0
    H, copy_all, operations = 1, 1, 1

    while H < n:
        if n % H == 0 and H != copy_all:
            copy_all = H
            operations += 1
        H = H + copy_all
        operations += 1

    if H == n:
        return operations
    return 0
