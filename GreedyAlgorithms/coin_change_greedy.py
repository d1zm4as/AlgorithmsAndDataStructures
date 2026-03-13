"""
Greedy coin change for canonical coin systems.
"""

def coin_change_greedy(coins, amount):
    coins = sorted(coins, reverse=True)
    result = []
    for coin in coins:
        while amount >= coin:
            amount -= coin
            result.append(coin)
    if amount != 0:
        return None
    return result


if __name__ == "__main__":
    coins = [1, 5, 10, 25]
    amount = 63
    result = coin_change_greedy(coins, amount)
    print("Coins used:")
    print(result)
