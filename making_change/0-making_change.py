#!/usr/bin/python3
""" This script defines the makeChange function. """


def makeChange(coins, total):
    """
    This function determine the fewest number of coins needed to meet a given
    amount total, given a pile of coins of different values.
    Args:
        coins (int): is a list of the values of the coins (integer numbers)
        total (int): represents the total number to meet.
    Returns:
        Fewest number of coins needed to meet total. If total is 0 or less,
        return 0. If total cannot be met by any number of coins you have,
        return -1.
    """
    if not isinstance(total, int) or total <= 0:
        return 0
    if (not isinstance(coins, list) or
            any(not isinstance(n, int) or n <= 0 for n in coins)):
        return 0
    coins_ordered = sorted(coins, reverse=True)
    i = 0
    n = len(coins)
    total_coins = 0
    while (i < n and total != 0):
        if total >= coins_ordered[i]:
            quotient = total // coins_ordered[i]
            total_coins += quotient
            total = total % coins_ordered[i]
        i += 1
    if total == 0:
        return total_coins
    else:
        return -1
