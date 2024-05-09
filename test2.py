from functools import cmp_to_key
n = int(input())
aa = [[0]*n for _ in range(5)]
inds = [dict() for i in range(5)]
for i in range(5):
    for j in range(n):
        aa[i][j] = int(input())
        inds[i][aa[i][j]] = j

res = aa[i][::]
def cmpr(x,y):
    votes = 0
    for i in range(5):
        if inds[i][x]<inds[i][y]:
            votes+=1
    if votes>=3:
        return -1
    elif votes==2:
        return 0
    return 1
res = sorted(res,key=cmp_to_key(cmpr))

assert len(res) == n
print("\n".join(map(str,res)))
