from functools import lru_cache
import sys
# Your task is to count the number of ways you can fill an n×m grid using 1×2 and 2×1 tiles.
sys.setrecursionlimit(3000) 
def countTiles(n,m):
    MOD = 10**9 + 7
    @lru_cache(None)
    def valid(cur,prev,last):
        if(last and cur>0):
            return False
        if(cur&prev>0): return False
        i =0
        while(i<n):
            if(cur&(1<<i)==0):
                if(prev&(1<<(i))==0 and i+1<n and cur&(1<<(i+1))==0 and prev&(1<<(i+1))==0): 
                    i+=1
                else: 
                    if(prev&(1<<(i))==0): return False
            i+=1
        return True
    @lru_cache(None)
    def count(k,prev_state):
        if(k==m): return 1;
        ways = 0
        for pos in range(0,2**n): # all possible states
            if(not valid(pos,prev_state,k==m-1)): continue
            # print(bin(pos),k,bin(prev_state))
            ways = (ways+ count(k+1,pos))%MOD
        return ways
    return count(0,0)

n,m = map(int,input().split())
print(countTiles(n,m))