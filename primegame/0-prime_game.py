#!/usr/bin/python3
"""
This module defines the isWinner function.
"""


def isWinner(x, nums):
    """
    This function determines the winner of each round of the prime game and
    returns the overall winner ("Maria" or "Ben"), or None if there is a tie.
    Args:
        x (int): Number of rounds
        nums (list): List of 'n' values for each round
    Returns:
        str or None: Name of the player that won the most rounds or None
    """
    if x < 1 or not nums:
        return None

    # Find the maximum value of n to limit our sieve
    max_n = max(nums)

    # Precompute primes up to max_n using a Sieve of Eratosthenes
    # and build a prefix array of prime counts
    # (prime_count[i] = number of primes <= i)
    sieve = [True] * (max_n + 1)
    sieve[0] = False
    sieve[1] = False

    for i in range(2, int(max_n**0.5) + 1):
        if sieve[i] is True:
            for j in range(i*i, max_n + 1, i):
                sieve[j] = False

    # Build the prime_count array
    prime_count = [0] * (max_n + 1)
    for i in range(1, max_n + 1):
        prime_count[i] = prime_count[i - 1]
        if sieve[i]:
            prime_count[i] += 1

    # Tally wins for Maria and Ben
    maria_wins = 0
    ben_wins = 0

    for n in nums:
        # If the count of primes up to n is odd => Maria wins, else Ben wins
        if prime_count[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
