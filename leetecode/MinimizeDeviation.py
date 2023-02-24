import heapq as hq
class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        pq = []
        for x in nums:
            if(x%2==0): pq.append(-x)
            else: pq.append(-x*2) # first increase all once
        mn = -max(pq) # since we can increase odd only onces
        hq.heapify(pq)
        res = float('inf')
        while(len(nums)==len(pq)): # can not delete any element from array
            num = -hq.heappop(pq) # check if we can get lower value by decreasing even
            res  = min(res,num-mn)
            if(num%2==0):
                mn = min(num//2,mn)
                hq.heappush(pq,-num//2)
        return res
        