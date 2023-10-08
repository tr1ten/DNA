from typing import List

def rec(a: , b: , c: , races: int, v: ) -> :
    res = c * races
    if a > 0:
        if b > 0:
            res += a * rec(0 if a < v else a - v, b + min(a, v) / 2, c + min(a, v) / 2, races + 1, v)
        else:
            res += a * rec(0 if a < v else a - v, b, c + min(a, v), races + 1, v)
    if b > 0:
        if a > 0:
            res += b * rec(a + min(b, v) / 2, 0 if b < v else b - v, c + min(b, v) / 2, races + 1, v)
        else:
            res += b * rec(a, 0 if b < v else b - v, c + min(b, v), races + 1, v)
    return res

# driver code
if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        c, m, p, v = map(, input().split())
        print("{:.12f}".format(rec(c, m, p, 1, v)))