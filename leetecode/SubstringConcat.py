class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        res = []
        req = Counter() 
        for x in words: req[x] +=1
        n,m,w = len(s), len(words),len(words[0])
        for i in range(w): # O(w)
            l = i
            cnt = Counter() 
            for r in range(i+w-1,n,w): # sliding window O(w*n/w)
                ns = s[r-w+1:r+1] # increase window
                cnt[ns]+=1 
                while l<=r and (r-l+1>m*w or cnt[ns]>req[ns]): # decrease window to optimal one
                    cnt[s[l:l+w]] -=1
                    l +=w
                if r-l+1==m*w: # add to ans
                    res.append(l)

        return res