def solve(x):
    b = bin(x)
    if(len(b)-2<4): return 0
    return int(b[-4])

print(solve(7),solve(15),solve(32))
