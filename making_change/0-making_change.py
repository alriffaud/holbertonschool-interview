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

    # We order from higher to minor to use the highest value coins first
    coins.sort(reverse=True)

    # Function to obtain an initial upper level with a voracious algorithm.
    def greedy_bound():
        remaining = total
        count = 0
        for coin in coins:
            if remaining <= 0:
                break
            count += remaining // coin
            remaining %= coin
        return count if remaining == 0 else float('inf')

    # Best [0] will save the best (minimum) amount of currencies found so far.
    best = [greedy_bound()]

    def dfs(i, current_total, count):
        # If we reach the total, we update the best solution.
        if current_total == total:
            best[0] = min(best[0], count)
            return

        # If we have already reviewed all the coins, we leave.
        if i >= len(coins):
            return

        coin = coins[i]
        # We estimate a lower limit:
        # We use the current currency to "cover" the remainder.
        lower_bound = count + ((total - current_total) + coin - 1) // coin
        if lower_bound >= best[0]:
            return

        # Si la moneda es 1, podemos completar la solución de inmediato.
        if coin == 1:
            best[0] = min(best[0], count + (total - current_total))
            return

        # If the currency is 1, we can complete the solution immediately.
        max_val = (total - current_total) // coin
        for x in range(max_val, -1, -1):
            new_count = count + x
            if new_count >= best[0]:
                # If we already use many coins, it makes no sense to continue
                # with X minor.
                break
            new_total = current_total + x * coin
            if new_total == total:
                best[0] = min(best[0], new_count)
                break
            dfs(i + 1, new_total, new_count)

    dfs(0, 0, 0)
    return best[0] if best[0] != float('inf') else -1
