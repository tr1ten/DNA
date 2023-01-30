from typing import List
import math
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        mat = [[0]*n for i in range(n)]
        cnt = 1
        for i in range(n//2):
            # upper row
            for x in range(i,n-i-1):
                mat[i][x] = cnt;
                cnt +=1
            # right col
            for y in range(i,n-i-1):
                mat[y][n-i-1] = cnt;
                cnt +=1
            # bottom row
            for x in reversed(range(i+1,n-i)):
                mat[n-i-1][x] = cnt;
                cnt +=1
            # left
            for y in reversed(range(i+1,n-i)):
                mat[y][i] = cnt;
                cnt +=1
        if(n%2==1):
            mat[n//2][n//2] = cnt
        return mat
    

def main():
    s = Solution()
    print(s.generateMatrix(3))
    print(s.generateMatrix(4))

main()

    