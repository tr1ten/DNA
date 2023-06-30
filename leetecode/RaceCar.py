class Solution:
    def racecar(self, target: int) -> int:
        LOGN = 30
        dp = [[float('inf')]*LOGN for i in range(target+1)] 
        dp[0][0] = 0
        for pos in range(target):
            for sp in range(LOGN): # 1 2 4 .. -1 -2 -4...
                asp = pos + ((2**sp) if sp<=14 else -(2**(sp-15)))
                # acceralte
                if asp>=0 and asp<=target: dp[asp][sp+1] = min(dp[asp][sp+1],dp[pos][sp] + 1)
                # reverse
                if sp<=14: dp[pos][15] = min(dp[pos][15],dp[pos][sp] +1  )
                else:  dp[pos][0] = min(dp[pos][0],dp[pos][sp] +1  )

        print(dp)
        return 0

class Solution:
    def racecar(self, target: int) -> int:
        q = deque()
        q.append((0,1,0))
        visited = set()
        visited.add((0,1))
        while(q):
            u,v,d = q.popleft()
            if u==target: return d
            if 0<u + v<=2*target and (u+v,2*v) not in visited : 
                visited.add((u+v,2*v))
                q.append((u+v,2*v,d+1))
            nxt = (u,-1 if v>0 else 1,d+1)
            if(nxt not in visited): 
                visited.add(nxt)
                q.append(nxt)
        

        