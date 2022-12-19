class Solution:
    def isPossible(self, n: int, edges: List[List[int]]) -> bool:
        adj = [set() for i in range(n)]
        for u,v in edges:
            adj[u-1].add(v-1)
            adj[v-1].add(u-1)
        
        odd = [i for i in range(n) if(len(adj[i])%2==1)]
        def f(a,b):
            return a not in adj[b];
        if(len(odd)==2):
            a,b = odd
            return any([f(a,i) and f(i,b) for i in range(n)]);
        if(len(odd)==4):
            a,b,c,d = odd;
            return (f(a,b) and f(c,d)) or (f(a,c) and f(b,d)) or (f(a,d) and f(b,c))
        return len(odd)==0