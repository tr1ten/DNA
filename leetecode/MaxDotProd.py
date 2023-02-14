class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        INF = 10**12
        @cache
        def solve(i,j):
            if(i==len(nums1) or j==len(nums2)): return -INF
            return max(nums1[i]*nums2[j]+solve(i+1,j+1),solve(i+1,j),solve(i,j+1))
        res = solve(0,0) # if we get -inf as ans that mean no positive sum exist thus need to handle this
        if(res==-INF): return max(max(nums1)*min(nums2),max(nums2)*min(nums1)) # either first contain all negative or second
        return res+INF