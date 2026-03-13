"""
Fibonacci with memoization.
"""

def fib(n, memo=None):
    if memo is None:
        memo = {}
    if n in memo:
        return memo[n]
    if n <= 1:
        return n
    memo[n] = fib(n - 1, memo) + fib(n - 2, memo)
    return memo[n]


if __name__ == "__main__":
    for i in range(10):
        print(f"fib({i}) = {fib(i)}")
