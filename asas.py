from collections import Counter
def solve(mat):
    m,n = len(mat),len(mat[0]) 
    ans = 0
    pref =Counter()
    cnt = Counter()
    for i in range(m):
        for j in range(n):
            ans += i*cnt[mat[i][j]] - pref[mat[i][j]]
        for j in range(n):
            cnt[mat[i][j]] += 1
            pref[mat[i][j]] += i
    
    # same for y distance
    pref = Counter()
    cnt = Counter()
    for j in range(n):
        for i in range(m):
            ans += j*cnt[mat[i][j]] - pref[mat[i][j]]
        for i in range(m):
            cnt[mat[i][j]] += 1
            pref[mat[i][j]] += j
    return ans

n,m = map(int,input().split())
mat = [list(map(int,input().split())) for i in range(n)]

print(solve(mat))