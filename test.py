from functools import *

@lru_cache(maxsize=10**5)
def rv(n, x):
    if n == 0: return 0
    ans = float('inf')
    for t in range(min(4, x + 1, n + 1)):
        ans = min(ans, (n - t) % 4 + rv((n - t) // 4, (x - t) // 4))
    return ans


def solve(n, x):
    n, d = divmod(n, 2)
    ans = float('inf')
    if d == 0: ans = min(ans, rv(n, 0))
    if x >= d: ans = min(ans, rv(n, (x - d) // 2) + 1)
    return ans


def main():
    for cas in range(int(input())):
        ans = solve(*map(int, input().split()))
        assert ans >= 0
        print(ans if ans < float('inf') else -1)

if __name__ == '__main__': main()
