from collections import Counter
class Solution:
    def wonderfulSubstrings(self, s: str) -> int:
        # use mask to represent states
        mask = 0;
        res = 0
        cnt = Counter()
        cnt[0] = 1
        for x in s:
            ind = ord(x)-ord('a')
            mask ^= (1<<ind)
            res += cnt[mask] # if this state appears before means there even substring in the middle
            # case 2: when we are allowed to have 1 odd in the middle, we try flipping each index and check for prev state
            for i in range(10):
                prefMask = mask^(1<<i)
                res += cnt[prefMask]
            cnt[mask] +=1
        return res
            
            

        