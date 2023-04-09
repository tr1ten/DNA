class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)
        dq = deque()
        dq.append((0,0))
        last = 0
        while(dq):
            u,s = dq.popleft()
            if(u==n-1): return s
            for v in range(max(u+1,last+1),u+1+nums[u]):
                dq.append((v,s+1))
            last = max(last,u+nums[u])
        return -1
            
