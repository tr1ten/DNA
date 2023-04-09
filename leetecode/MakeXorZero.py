class Solution:
    def minChanges(self, A: List[int], k: int) -> int:
        freq = [Counter([A[j] for j in range(i,len(A),k)]) for i in range(k)]
        cnt = [sum(freq[i].values() ) for i in range(k)]
        MAXN = 1<<10 
        dp = [float('inf')]*MAXN # dp[x]: min op to have cummulative XOR x at this grp (0...grp)
        for x in range(MAXN): dp[x] = cnt[0] - freq[0][x]
        for i in range(1,k):
            temp = dp[::]
            upper_bound = cnt[i]+ min(dp) # we know min of prev dp should be picked by a number 
            for x in range(MAXN):
                temp[x] = upper_bound
                for tar in freq[i]:
                    temp[x] = min(temp[x],cnt[i]-freq[i][tar] + dp[x^tar])
            dp = temp
        return dp[0]

         

