"""
0/1 Knapsack using dynamic programming.
"""

def knapsack_01(weights, values, capacity):
    n = len(weights)
    dp = [[0] * (capacity + 1) for _ in range(n + 1)]

    for i in range(1, n + 1):
        w = weights[i - 1]
        v = values[i - 1]
        for c in range(capacity + 1):
            if w > c:
                dp[i][c] = dp[i - 1][c]
            else:
                dp[i][c] = max(dp[i - 1][c], dp[i - 1][c - w] + v)

    return dp[n][capacity]


if __name__ == "__main__":
    weights = [2, 3, 4, 5]
    values = [3, 4, 5, 6]
    capacity = 5
    result = knapsack_01(weights, values, capacity)
    print(f"Max value: {result}")
