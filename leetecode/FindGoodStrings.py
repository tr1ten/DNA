def ps(s):
        arr = [0]*len(s)
        i,j = 1,0
        while(i<len(s)):
            if(s[i]==s[j]):
                arr[i] = j+1
                j +=1
                i+=1
            elif(j==0):
                arr[i] = 0
                i+=1
            else:
                j = arr[j-1] # can't just use j-1 since we don't know if smaller <j-1 are equal 
        return arr
class Solution:
    def findGoodStrings(self, n: int, s1: str, s2: str, evil: str) -> int:
        mod = 10**9 + 7
        lps = ps(evil)
        def dp(i,lower,upper,j):
            if(i==n): return 1
            if(j==len(evil)): return 0
            last = ord(s2[i] if upper else 'z');
            first= ord(s1[i] if lower else 'a')
            res = 0
            for i in range(first,last+1):
                c = chr(i)
                _lower = lower and c==s1[i]
                _upper = upper and c==s2[i]
                _j = j
                while _j and evil[_j]!=c:
                    _j = lps[_j-1]
                res += dp(i+1,_lower,_upper,j+1);
                res %= mod
            return res
        return dp(0,True,True,0)
            