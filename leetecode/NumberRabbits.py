class Solution:
    def numRabbits(self, A: List[int]) -> int:
        d = defaultdict(int);
        res = 0
        for x in A: 
            res +=1
            if(d[x]>0):
                d[x] -=1
            else:
                d[x] = x
        return res + sum(d.values())