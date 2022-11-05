class Solution:
    def partition(self, s: str) -> List[List[str]]:
        mem = dict()
        def solve(idx):
            if(idx==len(s)): return [[]]
            if(idx in mem): return mem[idx]
            ret = []
            for i in range(idx,len(s)):
                sb = s[idx:i+1]
                if(sb[::-1]==sb):
                    ret += [[sb]+pal for pal in solve(i+1)]
            mem[idx] = ret
            return ret
        return solve(0)