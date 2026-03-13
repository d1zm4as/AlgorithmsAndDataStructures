"""
Longest Increasing Subsequence (O(n^2)).
"""

def lis(sequence):
    n = len(sequence)
    if n == 0:
        return 0
    dp = [1] * n

    for i in range(n):
        for j in range(i):
            if sequence[j] < sequence[i]:
                dp[i] = max(dp[i], dp[j] + 1)
    return max(dp)


if __name__ == "__main__":
    seq = [10, 9, 2, 5, 3, 7, 101, 18]
    print(f"LIS length: {lis(seq)}")
