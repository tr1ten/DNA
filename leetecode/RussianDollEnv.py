from sortedcontainers import SortedList
class Solution:
    def maxEnvelopes(self, nums: List[List[int]]) -> int:
        nums.sort(key=lambda x:(x[0],-x[1])) # sort acc to width, then descdening height this ensures same widhth will not be the part of same LIS
        sc = SortedList()
        res = 0
        for w,h in nums:
            idx = sc.bisect_left(h)
            if(idx!=len(sc)): del sc[idx]
            sc.add(h)
        return len(sc)