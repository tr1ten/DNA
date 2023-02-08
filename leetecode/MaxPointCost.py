class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        n,m = len(points),len(points[0])
        score = [points[i][:] for i in range(n)] # score[r][c]:  max possible score at (r,c)
        for r in range(1,n):
            cp = 0
            for c in range(0,m):
                if(score[r-1][c]>score[r-1][cp]-abs(c-cp)): cp = c
                score[r][c] = max(score[r][c],points[r][c]+score[r-1][cp]-abs(c-cp))
            cp = m-1
            for c in reversed(range(0,m)):
                if(score[r-1][c]>score[r-1][cp]-abs(c-cp)): cp = c
                score[r][c] = max(score[r][c],points[r][c]+score[r-1][cp]-abs(c-cp))
        return max(score[-1])