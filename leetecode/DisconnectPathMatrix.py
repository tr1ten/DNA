class Solution:
    """
        First dfs set all cells for single sucess path to zero and then dfs again to check if there is a another path after blocking the first one.
        
    """
    def isPossibleToCutPath(self, grid: List[List[int]]) -> bool:
        n,m  =len(grid), len(grid[0])
        def dfs(i,j):
            if(i==n-1 and j==m-1): return True
            if(i>=n or j>=m or grid[i][j]==0): return False
            if(i!=0 or j!=0): grid[i][j] = 0
            return dfs(i+1,j) or dfs(i,j+1) # order of dfs is important
        return not dfs(0,0) or (not dfs(0,0))