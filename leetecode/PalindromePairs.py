def isPali(x):
    i = 0
    j = len(x)-1
    while(i<j):
        if(x[i]!=x[j]): return False
        i +=1
        j -=1
    return True


class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        dc = dict()
        for i in range(len(words)): dc[words[i]] = i
        # case 1: empty string and pali
        res = []
        if("" in dc):
            v = dc[""]
            for x in words:
                if(isPali(x)): 
                    res.append((v,dc[x]))
                    res.append((dc[x],v))
        # case 2
        for i in range(len(words)):
            for j in range(len(words[i])):
                rw = words[i][:j+1][::-1]
                if(isPali(words[i][j+1:]) and rw in dc):
                    res.append((i,dc[rw]))
                rw =  words[i][j+1:][::-1]
                if(isPali(words[i][:j+1]) and rw in dc):
                    res.append((dc[rw],i))
        return res



