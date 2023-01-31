from collections import defaultdict
class Solution:
    def matchReplacement(self, s: str, sub: str, mappings: List[List[str]]) -> bool:
        mp = defaultdict(set)
        for x,y in mappings:
            mp[x].add(y)
        for i in range(len(s)-len(sub)+1):
            found = True
            marked = {}
            for j in range(len(sub)):
                if(s[i+j]!=sub[j] and ((sub[j] in marked and s[i+j]!=marked[sub[j]]) or (sub[j] not in marked and s[i+j] not in mp[sub[j]])) ):
                    found = False
                    break
                if(s[i+j]!=sub[j]):
                    marked[sub[j]] = s[i+j]
            if(found): return True
        return False
