class Solution:
    def numOfWays(self, N: int) -> int:
        def gm(state):
            mask = 0
            mp = {"R":1,"G":2,"Y":3}
            i =  0
            for c in state:
                mask |= 1<<(mp[c]+3*i)
                i+=1
            return mask
        states = ["RYR","YRY","GRY","RYG","YRG","GRG","RGR","YGR","GYR","RGY","YGY","GYG"] # total possible states
        masks = [gm(state) for state in states]
        print(masks)
        mod = 10**9 + 7
        @cache
        def f(n,state):
            if(n==0): return 1
            res = 0
            for n_state in states:
                if(not all([x!=y for x,y in zip(n_state,state)])): continue
                res += f(n-1,n_state)
                res %=mod
            return res
        return sum([f(N-1,x) for x in states])%mod
    
# matrix exponentiation
import numpy as np
class Solution:
    def numOfWays(self,N: int) -> int:
        mat = np.matrix([[0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0], [1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1], [1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0], [0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0], [1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0], [1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0], [0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1], [0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1], [0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0], [0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1], [1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1], [0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0]])
        state = np.array([1]*12)
        mod = 10**9 + 7
        prod = np.eye(12)
        for i in range(N-1): prod = np.mod(prod*mat,mod)
        mx =  np.dot(prod,state)
        return int(np.sum(mx)%mod)