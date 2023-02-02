from functools import cmp_to_key

class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        rank = {x:i for i,x in enumerate(order)}
        for i in range(len(words)-1):
            for c1,c2 in zip(words[i],words[i+1]):
                if(rank[c1]>rank[c2]): 
                    return False
                if(rank[c1]<rank[c2]): 
                    break
            if(words[i]!=words[i+1] and words[i].startswith(words[i+1])): return False
        return True