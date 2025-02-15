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

    # Initialize a list to store the minimum coins needed for each amount
    # up to total
    dp = [float('inf')] * (total + 1)
    dp[0] = 0  # Base case: 0 coins are needed to make total 0

    # Fill the dp array
    for coin in coins:
        for amount in range(coin, total + 1):
            dp[amount] = min(dp[amount], dp[amount - coin] + 1)

    return dp[total] if dp[total] != float('inf') else -1
