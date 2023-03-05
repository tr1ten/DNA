class Solution:
    def waysToReachTarget(self, target: int, types: List[List[int]]) -> int:
        mod = 10**9 + 7
        dp = [[0]*(target+1) for i in range(len(types)+1)]
        dp[0][0] = 1 # base case
        for idx in range(1,len(types)+1):
            for amt in range(target+1):
                for i in range(0,types[idx-1][0]+1):
                    if(amt-i*types[idx-1][1]<0): break
                    dp[idx][amt] +=dp[idx-1][amt-types[idx-1][1]*i] 
                    dp[idx][amt] %=mod
        return dp[-1][-1]
                
        