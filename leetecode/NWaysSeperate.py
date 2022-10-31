# toughest dp question
class Solution:
    def numberOfCombinations(self, num: str) -> int:
        n = len(num)
        ps = [[0]*(n+1) for _ in range(n+1)]
        ps2 = [[0]*(n+1) for _ in range(n+1)]
        mod = 10**9+7
        for i in range(n-2,-1,-1):
            for j in range(i+1,n):
                if num[i]==num[j]:
                    ps2[i][j] = 1 + ps2[i+1][j+1]
                else:
                    ps2[i][j] = 0
        for i in range(n):
            for l in range(1,i+2):
                j = i-l+1;
                ss = 0
                if num[j]=='0':
                    s = 0
                elif j==0:
                    s = 1
                else:
                    ml2 = 0
                    if j<l:
                        ml2 = j
                    else:
                        cl = ps2[j-l][j]
                        if cl>=l or num[j-l+cl]<num[j+cl]:
                            ml2 = l
                        else:
                            ml2 = l-1
                    s = ps[j-1][ml2]
                ps[i][l] = (s+ps[i][l-1])
        return ps[n-1][n]%mod