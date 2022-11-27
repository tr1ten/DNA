from functools import cache
class Solution:
    # O(n^3)
    def mergeStones(self, stones: List[int], k: int) -> int:
        n = len(stones)
        inf = 2**30 # invalid case
        if((n-1)%(k-1)>0): return -1; # n-m*(k-1) = 1 since each step we are reducing by k and adding 1
        pref = [0]*(n+1)
        for i in range(1,n+1): pref[i] = pref[i-1] + stones[i-1];
        @cache
        def f(i,j,p): # min cost of merging stones (i...j) into p piles 
            if(i==j): return 0 if p==1 else inf; # cost of merging single stone into p piles
            if(p==1): return f(i,j,k) + pref[j+1]-pref[i] # to merge into 1 pile we first need min k piles
            else:
                return min([f(i,i+m,1)+f(i+m+1,j,p-1) for m in range(j-i)]); # minimize the split of 1:p-1 stones 
        return f(0,n-1,1);
            