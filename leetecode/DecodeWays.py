from functools import cache
class Solution:
    def numDecodings(self, s: str) -> int:
        MOD = 10**9 + 7
        @cache
        def solve(idx):
            if(idx<0): return 1
            res = 0
            if(s[idx]!='0'): res += solve(idx-1)*(1 if(s[idx]!='*') else 9)
            if(idx==0 or s[idx-1]=='0' or s[idx-1]>'2'): return res;
            res %= MOD
            mul = 0
            if(s[idx-1]!='*'): # xy if x not *
                if((s[idx]!='*') and (s[idx-1]+s[idx])>='27'): return res # x can't be 0 or xy can't be greator than 26
                mul = 1
                if(s[idx-1]=='1' and s[idx]=='*'): mul = 9
                if(s[idx-1]=='2' and s[idx]=='*'): mul = 6
            else:
                mul  = (1 if(s[idx]!='*') else 9) # xy = *[0-9] 
                if(s[idx]=='*' or s[idx]<'7'): mul += (1 if(s[idx]!='*') else 6)
            res = (res+solve(idx-2)*mul)%MOD
            return res
        return solve(len(s)-1)