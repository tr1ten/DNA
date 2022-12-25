import bisect
class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort();
        pref = [0]*(len(nums)+1);
        res = [0]*(len(queries))
        for i in range(1,len(nums)+1): pref[i] = pref[i-1]+nums[i-1];     
        def floor(sc, value):
            i = bisect.bisect_right(sc,value) - 1
            if i < 0:
                return None
            return i
        for i,q in enumerate(queries):
            res[i] = floor(pref,q)
        return res
