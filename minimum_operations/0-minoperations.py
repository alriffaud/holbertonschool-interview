#!/usr/bin/python3
""" This module defines the minOperations function. """


def is_prime(x):
    """
    This function evaluates if x is a prime number.
    Args:
        x (int): The number to evaluete.
    Returns: True if x is a prime number. False if it's not.
    """
    i = 2
    while (x % i != 0 and i * i < x):
        i += 1
    if (x % i == 0):
        return False
    else:
        return True


def divisors(n):
    """
    This function finds and adds to a list the divisors of n and the previous
    number of the list until reaching a prime number.
    Args:
        n (int): Is the initial number and first element of the list.
    Returns: A list of divisors of n with the previous conditions.
    """
    div_list = [n]
    i = n // 2
    anterior = n
    while (i > 0):
        if (anterior % i == 0):
            div_list.append(i)
            anterior = i
            if (is_prime(i) or i == 2):
                break
            i = i // 2  # To don't have to iterate so many times unnecessarily
        else:
            i -= 1
    return div_list


def minOperations(n):
    """
    This function calculates the fewest number of operations needed to result
    in exactly n H characters in the file.
    Args:
        n (int): The number of characters to be printed.
    Returns: The fewest number of operations needed to result in exactly n H.
    If n is impossible to achieve, return 0.
    """
    if n <= 1:
        return 0
    div = divisors(n)
    i = 0
    operations = 0
    while (i < len(div) - 1):
        operations += div[i] // div[i + 1]
        i += 1
    operations += div[i]
    return operations
