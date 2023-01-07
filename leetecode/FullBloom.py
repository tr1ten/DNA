import bisect
class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], persons: List[int]) -> List[int]:
        start = sorted([x[0] for x in flowers])
        end = sorted([x[1] for x in flowers])
        res = []
        for x in persons:
            op = bisect.bisect_right(start,x)
            cl = bisect.bisect_right(end,x)
            res.append(op-cl+1)
        return res
            
        

