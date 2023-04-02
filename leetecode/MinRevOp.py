from sortedcontainers import SortedSet
class Solution:
    def minReverseOperations(self, n: int, p: int, bn: List[int], k: int) -> List[int]:
        res = [-1]*n
        res[p] = 0
        no_need = [False]*n
        no_need[p] = True
        for i in bn: no_need[i] = True
        q = deque() # bfs where nodes are the position of 1
        q.append((p,0))
        ev = SortedSet([i for i in range(0,n,2) if(not no_need[i]) ]) # important to make TC O(N)
        od = SortedSet([i for i in range(1,n,2) if(not no_need[i]) ])
        while(q):
            pp,m = q.popleft()
            left,right = max(0,pp-k+1),min(pp+1,n-k+1) # find range for starting positions of K len array containing 1
            c = k-1-pp # constant as per the eq
            ls = ev if (2*left+c)%2==0 else od # select the correct list
            st = ls.bisect_left(2*left+c) # find begining position
            end = ls.bisect_left(2*right+c) # ending position
            sl = ls[st:end] # create a view 
            for i in sl:
                ls.remove(i) # cut the original arr
                res[i] = m+1
                q.append((i,m+1))
        return res