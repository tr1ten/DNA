class Solution:
    def solve(self,n,k,stalls):
        stalls.sort()
        def check(diff):
            i = 0
            temp = k-1
            for j in range(n):
                if(temp==0): return True
                if((stalls[j]-stalls[i])>=diff):
                    i = j
                    temp -=1
            return temp==0
        high = 10**9
        low = 0
        while(low<high):
            mid = (low+high)//2;
            if(check(mid)):
                low = mid+1
            else:
                high = mid
        return low-1