class Solution:
    def maximizeWin(self, A, k):
        def f(B): # find max segment of atmost len k
            ans = [0]*(len(B)+1) # ans[i]: max len of segment that can be formed by taking first i elements
            i = 0
            for j in range(len(B)):
                while(abs(B[j]-B[i])>k): i+=1 # valid window condition
                ans[j+1] = max(ans[j],j-i+1) 
            return ans
        left,right = f(A),f(A[::-1])[::-1] # max len from start & end
        return max([left[i]+right[i] for i in range(len(A))])