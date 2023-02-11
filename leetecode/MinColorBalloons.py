class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        sm = 0
        mx = 0
        colors +="$" # dummy end
        neededTime.append(0)
        last = None
        res = 0
        for c,t in zip(colors,neededTime):
            if(c!=last):
                res += sm-mx
                sm = 0
                mx = 0
                last = c
            mx = max(t,mx)
            sm +=t

        return res