class Solution:
    def rangeAddQueries(self, n: int, queries: List[List[int]]) -> List[List[int]]:
        df = [[0]*(n+1) for _ in range(n)]
        # Does range update
        def update(D, l, r, x):
            D[l] += x
            D[r + 1] -= x
        def printArray(A, D):
            for i in range(0 , len(A)):
                if (i == 0):
                    A[i] = D[i]
        
                # Note that A[0] or D[0] decides
                # values of rest of the elements.
                else:
                    A[i] = D[i] + A[i - 1]
        
            return A
        for r1,c1,r2,c2 in queries:
           for r in range(r1,r2+1):
               update(df[r],c1,c2,1)
        return [printArray([0]*n,df[i])  for i in range(n)]
        
        
                
        
        