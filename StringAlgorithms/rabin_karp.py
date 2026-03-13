"""
Rabin-Karp string search (single pattern).
"""

def rabin_karp(text, pattern, base=256, mod=101):
    n = len(text)
    m = len(pattern)
    if m == 0 or m > n:
        return []

    h = pow(base, m - 1, mod)
    p_hash = 0
    t_hash = 0
    matches = []

    for i in range(m):
        p_hash = (base * p_hash + ord(pattern[i])) % mod
        t_hash = (base * t_hash + ord(text[i])) % mod

    for i in range(n - m + 1):
        if p_hash == t_hash:
            if text[i:i + m] == pattern:
                matches.append(i)
        if i < n - m:
            t_hash = (base * (t_hash - ord(text[i]) * h) + ord(text[i + m])) % mod
            if t_hash < 0:
                t_hash += mod

    return matches


if __name__ == "__main__":
    text = "GEEKS FOR GEEKS"
    pattern = "GEEK"
    print(rabin_karp(text, pattern))
