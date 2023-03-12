import heapq
class Solution:
    def findMinimumTime(self, tasks: List[List[int]]) -> int:
        tasks.sort(key=lambda x:(x[1],x[0]))
        res = 0
        st = set()
        for s,e,d in tasks:
            for i in range(s,e+1): 
                if(i in st): d-=1
            for i in range(e,s-1,-1):
                if(d<=0): break
                if(i in st): continue
                st.add(i)
                d -=1
                res +=1
        return res