class Solution:
    def shortestSequence(self, rolls: List[int], k: int) -> int:
        vis = set()
        res = 1
        for x in rolls:
            if(x not in vis):
                vis.add(x)
                if(len(vis)==k): 
                    res+=1
                    vis.clear()
        return res
                