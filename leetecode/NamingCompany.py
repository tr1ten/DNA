from collections import defaultdict
import string
class Solution:
    def distinctNames(self, ideas: List[str]) -> int:
        d = defaultdict(set)
        n = len(ideas)
        for w in ideas: d[w[0]].add(w[1:])
        its = [[set() for i in range(26)] for i in range(26)]
        for c1 in string.ascii_lowercase:
            for c2 in string.ascii_lowercase:
                its[ord(c1)-ord('a')][ord(c2)-ord('a')] = d[c1].intersection(d[c2])
        res = n*n
        for w in ideas:
            sffx = w[1:]
            for c in string.ascii_lowercase:
                ivt = its[ord(c)-ord('a')][ord(w[0])-ord('a')]
                if(sffx in ivt): res -= len(d[c])
                else: res -= len(ivt)
        #     print(res)
        # print(d)
        return res