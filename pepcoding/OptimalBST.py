def f(l,r,dp,pref):
    if(l>r): return 0
    if(l==r): return pref[r+1]-pref[l]
    if(dp[l][r]!=-1): return dp[l][r]
    res = float('inf')
    for i in range(l,r+1):
        res = min(res,pref[r+1]-pref[l] +  f(l,i-1,dp,pref) + f(i+1,r,dp,pref))
    return res
def main():
    N = int(input())
    keys = [0]*N
    freq = [0]*N
    dp = [[-1]*N for i in range(N)]
    pref = [0]*(N+1)
    for i in range(N):
        keys[i] = int(input())
    for i in range(N):
        freq[i] = int(input())
    for i in range(N):
        pref[i+1] = pref[i] + freq[i]
    print(f(0,N-1,dp,pref));
if __name__ == '__main__':
    main()