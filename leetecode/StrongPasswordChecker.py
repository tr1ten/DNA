class Solution:
    def strongPasswordChecker(self, s: str) -> int:
        @cache
        def solve(i,low,up,dig,last,cnt,d,ins):
            if i==len(s):
                c = (not low) + (not up) + (not dig)
                if(i-d+ins>20): return c + i+ins-d-20
                if(i-d+c+ins <6): return 6-(i-d+ins)
                return c
            if not low and s[i] in string.ascii_lowercase: low = True
            if not up and s[i] in string.ascii_uppercase: up = True
            if not dig and s[i] in string.digits: dig = True
            cnt =  cnt+1 if (s[i]==last) else 1
            if cnt==3: 
                # insert character x 3, replace character x 3, delete character x 1
                res = 1+min(
                    solve(i+1,low,up,dig | 1,"$",1,d,ins+1),solve(i+1,low,up | 1,dig,"$",1,d,ins+1),solve(i+1,low | 1 ,up,dig,"$",1,d,ins+1)
                    ,solve(i+1,low,up,dig | 1,"$",1,d,ins),solve(i+1,low,up | 1,dig,"$",1,d,ins),solve(i+1,low | 1 ,up,dig,"$",1,d,ins),solve(i+1,low,up,dig,last,cnt-1,d+1,ins))
                return res
            return solve(i+1,low,up,dig,s[i],cnt,d,ins)
        return solve(0,0,0,0,'#',0,0,0)