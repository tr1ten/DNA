class Solution:
    def minStickers(self, st: List[str], target: str) -> int:
        dp = defaultdict(lambda :float('inf'))
        dp[0] = 0 
        n=len(target)
        N = 1<<n
        for mask in range(N):
            if mask not in dp: continue # reduce waste computation
            for x in st:
                nxt = mask
                for c in x:
                    for r in range(n):
                        if target[r]==c and (nxt&(1<<r))==0:
                            nxt |= (1<<r)
                            break # take only once
                dp[nxt] = min(dp[nxt],dp[mask] + 1)
        return -1 if dp[N-1]==float('inf') else dp[N-1]
