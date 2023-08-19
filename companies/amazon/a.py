import math
def solve(A):
    res = 0
    c = dict()
    for x in A:
        if x in c:
            res += c[x]
            c[x] = math.ceil(c[x]/2)
        else:
            res +=x
            c[x] = math.ceil(x/2)
    return res
print(solve([5,5,3,6,5,3]))
print(solve([8,4,4,8,2]))
