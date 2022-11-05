class Solution:
    def countSpecialNumbers(self, n: int) -> int:
        s = str(n)
        def mxd(d):
            if(d==0): return 0
            p = 1
            for i in range(0,d):
                p *= (10-i-(1 if i==0 else 0))
            return p + mxd(d-1)
        def solve(idx,visited):
            if(idx>=len(s)): return 1
            sb = int(s[idx])
            pos = 0
            flag = False
            for i in range(sb,0 if idx==0 else -1,-1):
                if(visited[i]==False): pos +=1
                elif sb==i: flag = True
            c = 0
            for i in range(10):
                c += 1 if visited[i] else 0
            res = 0
            if(not flag):
                pos -=1
            if(pos>0):
                p = pos
                for i in range(1,len(s)-idx):
                    p *= (10-i-c)
                res +=p
            if(flag): return res
            visited[sb] = True
            return res + solve(idx+1,visited)    
        return solve(0,[False for i in range(10)]) + mxd(len(s)-1)