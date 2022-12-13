class Solution:
    def canPlaceFlowers(self, A: List[int], n: int) -> bool:
        if(n==0): return True
        for i in range(len(A)):
            if(A[i]==0 and (i==0 or A[i-1]==0) and (i==len(A)-1 or A[i+1]==0)): 
                A[i] = 1
                n-=1
            if(n==0): return True
        return False