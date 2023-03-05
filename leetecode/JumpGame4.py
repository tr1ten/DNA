class Solution:
    def minJumps(self, arr: List[int]) -> int:
        inx = defaultdict(list)
        for i,x in enumerate(arr): inx[x].append(i)
        q = deque()
        vis = set()
        q.append((0,0))
        vis.add(0)
        values = set()
        while(q):
            s,u = q.popleft()
            if(u==len(arr)-1): return s
            if(arr[u] not in values):
                for v in inx[arr[u]]:
                    if(v not in vis): q.append((s+1,v))
            values.add(arr[u])
            if(u+1<len(arr) and u+1 not in vis): 
                vis.add(u+1)
                q.append((s+1,u+1))
            if(u-1>=0 and u-1 not in vis): 
                vis.add(u-1)
                q.append((s+1,u-1))
        return -1


            