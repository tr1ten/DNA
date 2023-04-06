#
# @lc app=leetcode id=1681 lang=python
#
# [1681] Minimum Incompatibility
#

# @lc code=start
class Solution:
    def minimumIncompatibility(self, A: List[int], k: int) -> int:
        n = len(A)
        A.sort()
        subset_size = n//k;
        N = 1<<n
        dp = [[float('inf')]*n for i in range(N)]
        for state in range(N):
            # check if state is valid that is no duplicate
            n_z = state.bitcount() # number of elements present
            cnt = [0]*17
            for i in range(n):
                if(state&(1<<i)): cnt[A[i]] += 1
            if(max(cnt)>-n_z/subset_size): continue
            if(n_z%subset_size): # if need to add more el to make it a grp
                for i,j in combinations(range(n),2):
                    if(i!=j and state&(1<<i) and state&(1<<j)):
                        dp[state] = min(dp[state],dp[state^(1<<i)] + )
            

        return dp[N-1] if(dp[N-1] != float('inf')) else -1

# @lc code=end

