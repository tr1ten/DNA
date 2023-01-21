class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        res = set()
        def solve(idx,ans):
            if(len(ans)>1):
                res.add(tuple(ans))
            if(idx==len(nums)): return;
            solve(idx+1,ans)
            if(not ans or ans[-1]<=nums[idx]):
                ans.append(nums[idx])
                solve(idx+1,ans)
                ans.pop()
        solve(0,[])
        return res
