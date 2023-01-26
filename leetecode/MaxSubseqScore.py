import heapq
class Solution:
    def maxScore(self, nums1: List[int], nums2: List[int], k: int) -> int:
        n = len(nums1)
        srt = [i for i in range(n)]
        srt.sort(key=lambda x:-nums2[x]) # sort based on second array from big to small
        res = float('-inf')
        sm = 0
        h = []
        for j in range(n):
            sm +=nums1[srt[j]] # calculate sum of indices before min 
            heapq.heappush(h,nums1[srt[j]])
            if(len(h)>k): 
                sm -= heapq.heappop(h) # greedy:  remove the element of first which contribute minimum to the sum
            if(len(h)==k): res = max(res,sm*nums2[srt[j]]) # calculate the ans since last element encounter will be the min
        return res