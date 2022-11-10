class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        def solve(idx,m,n):
            if((m==0 and n==0) or idx>=len(strs)):
                return 0
            
            res = solve(idx+1,m,n)
            zc = strs[idx].count("0")
            oc = strs[idx].count("1")
            if(zc<=m and oc<=n):
                res = max(res,1+solve(idx+1,m-zc,n-oc))
            return res
            
        return solve(0,m,n)