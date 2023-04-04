#
# @lc app=leetcode id=1494 lang=python3
#
# [1494] Parallel Courses II
#

# @lc code=start
from collections import deque
class Solution:
    def minNumberOfSemesters(self, n: int, relations: List[List[int]], k: int) -> int:
        adj = [[] for i in range(n)]
        ind = [0]*n
        for u,v in relations:
            adj[u-1].append(v-1)
            ind[v-1] +=1
        dq = deque()
        for  i in range(n): 
            if(not ind[i]): dq.append(i)
        res = 0
        while(dq):
            sz = len(dq)
            for i in range(sz):
                u = dq.popleft()
                for v in adj[u]:
                    ind[v] -=1
                    if(ind[v]==0): dq.append(v)
            res += sz//2 + sz%2;
        return res
            
        
        
# @lc code=end

