#
# @lc app=leetcode id=975 lang=python3
#
# [975] Odd Even Jump
#

# @lc code=start
from sortedcontainers import SortedList
class Solution:
    def oddEvenJumps(self, arr: List[int]) -> int:
        n = len(arr)
        st = SortedList()
        gnxt = [n]*n # next *min* greator element
        for i in reversed(range(n)):
            st.add((arr[i],i))
            ind = st.bisect_right((arr[i],i))
            if(ind<len(st)): gnxt[i] = st[ind][1]
        st = SortedList()
        snxt = [n]*n # next *max* lesser element
        for i in reversed(range(n)):
            st.add((arr[i],-i))
            ind = st.bisect_left((arr[i],-i))
            if(ind-1>=0): snxt[i] = -st[ind-1][1]
        dp = [[False,False] for i in range(n+1)] # basic dp stuff, dp[i][odd?] - if we can reach last node from i if odd step
        dp[n-1] = [True,True]
        res = 0
        for i in range(n-2,-1,-1):
            for k in range(2):
                m = snxt if k==0 else gnxt
                dp[i][k] |= dp[m[i]][k^1]
            res += dp[i][1]
        return res+1

# @lc code=end

