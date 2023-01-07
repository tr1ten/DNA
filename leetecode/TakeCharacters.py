class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        cnt = {'a':0,'b':0,'c':0}
        for x in s: cnt[x] +=1
        i = 0
        if(min(cnt.values())<k): return -1
        res = 10**10
        for j in range(len(s)):
            cnt[s[j]] -=1
            while(min(cnt.values())<k):
                cnt[s[i]] +=1
                i +=1
            res = min(res,len(s)-(j-i+1))
        return res
            