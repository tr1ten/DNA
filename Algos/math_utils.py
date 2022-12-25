def fast_pow(a, b, m):
    if b == 0:
        return 1
    if b == 1:
        return a % m
    if b % 2 == 0:
        return fast_pow(a * a % m, b // 2, m)
    else:
        return a * fast_pow(a * a % m, b // 2, m) % m

def fact(n,m):
    if n == 0:
        return 1
    return n * fact(n-1,m) % m

def gcd(a,b):
    if b == 0:
        return a
    return gcd(b, a % b)