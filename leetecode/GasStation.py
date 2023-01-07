class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        i = 0
        sm = 0
        for j in range(2*len(gas)):
            idx = j%len(gas)
            if(sm+gas[idx]-cost[idx]<0):
                i = j+1
                sm = 0
            else:
                sm += gas[idx]-cost[idx]
                if(j>i and idx==i):
                    return i
        return -1



            