import string
from collections import deque,Counter
class Solution:
    def longestSubsequenceRepeatedK(self, s: str, k: int) -> str:
        cnt = Counter(s)
        cd = Counter() # candidates character that can be part of answer
        for x in cnt:
            if(cnt[x]>=k):
                cd[x] = cnt[x]//k
        # now try all possible answer efficiently using bfs
        q = deque()
        def is_subseq(x, y):
            it = iter(y)
            return all(c in it for c in x)
        q.append("")
        cds = sorted(cd.keys(),reverse=True)
        res = ""
        while(q):
            ss = q.popleft()
            if(len(ss)>len(res)): res = ss
            for c in cds:
                if(cd[c]-ss.count(c)>0 and is_subseq((ss+c)*k,s)): q.append(ss+c);
        return res