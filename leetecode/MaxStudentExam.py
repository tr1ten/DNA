class Solution:
    def maxStudents(self, seats: List[List[str]]) -> int:
        n = len(seats)
        m = len(seats[0])
        def canPut(i,j,lr,cr):
            if(i<0 or j<0 or j>=m or i>=n or cr[j]!='.'): return False
            if(j>0 and lr[j-1]=='o'): return False
            if(j<m-1 and lr[j+1]=='o'): return False
            if(j>0 and cr[j-1]=='o'): return False
            if(j<m-1 and cr[j+1]=='o'): return False
            return True
        
        @cache
        def solve(i,j,lr,cr):
            if(i>=n and j>=m):
                return 0
            if(j>=m):
                if(i==n-1): return 0
                return solve(i+1,0,cr,tuple(seats[i+1]))
            res = solve(i,j+1,lr,cr)
            if(canPut(i,j,lr,cr)):
                cr = list(cr)
                cr[j] = 'o' # random placeholder to represent filled seat
                res = max(1+solve(i,j+1,lr,tuple(cr)),res)
                cr[j] = '.'
            return res
        lr = ('.')*m
        cr = tuple(seats[0])
        return solve(0,0,lr,cr)