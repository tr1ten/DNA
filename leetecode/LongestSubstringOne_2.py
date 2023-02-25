from sortedcontainers import SortedList,SortedDict
from typing import List
class Solution:
    def longestRepeating(self, s: str, queryCharacters: str, queryIndices: List[int]) -> List[int]:
        n = len(s)
        lens = SortedDict() # lengths sorted order
        m = SortedList() # contain repeated intervals (start,end,char)
        m.add((-1,-1,'')) # handle edge case
        m.add((n,n,''))
        # helper functions
        def add(start,end,c): # add interval 
            m.add((start,end,c))
            lens[end-start+1] =lens.get(end-start+1,0) + 1
        def rm(ival): # remove interval
            m.remove(ival)
            ln = ival[1]-ival[0] + 1
            lens[ln] -=1
            if(lens[ln]<=0): del lens[ln]
        # building the m and lens
        i = 0
        while(i<n):
            c = s[i]
            start = i
            while(i<n and s[i]==c): i += 1
            add(start,i-1,c)
        def query(index,nc): # replace character at specific index
            pos = m.bisect_right((index,index,''))
            if(m[pos][0]>index): pos -=1 
            ival = m[pos]
            if(ival[2]==nc): return lens.peekitem()[0]; # no change if same as old character
            prev,nxt = m[pos-1],m[pos+1] # get adjacent interval for possible merge
            cur = [index,index,nc]
            if(ival[0]==index and prev[2]==nc): # try to merge with prev
                cur[0] = prev[0]
                rm(prev)
            if(ival[1]==index and nxt[2]==nc): # merge with next
                cur[1] = nxt[1]
                rm(nxt)
            rm(ival)
            if(cur): add(*cur)
            if(ival[0]<cur[0]): add(ival[0],cur[0]-1,ival[2]) # split left
            if(ival[1]>cur[1]): add(cur[1]+1,ival[1],ival[2]) # split right
            return lens.peekitem()[0]
        return [query(j,queryCharacters[i]) for i,j in enumerate(queryIndices)]