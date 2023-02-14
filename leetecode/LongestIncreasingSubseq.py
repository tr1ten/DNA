from sortedcontainers import SortedList
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        sc = SortedList()
        for x in nums:
            if(sc.bisect_left(x)!=len(sc)): del sc[idx]
            sc.add(x)
        return len(sc)
        