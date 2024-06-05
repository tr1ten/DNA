A = 2
MX = 32;
class Node:
    def __init__(self) -> None:
        self.childs = [None]*A
        self.ended = False
        self.val = -1
        self.cnt = 0
def add(root,x):
    cur = root
    for i in range(MX,-1,-1): # store from msb...lsb
        ind = (x>>i)&1
        if not cur.childs[ind]: cur.childs[ind] = Node()
        cur = cur.childs[ind]
    cur.ended = 1;
    cur.cnt+=1
    cur.val = x

def remove(root,x):
    cur = root
    path = []
    for i in range(MX,-1,-1): # store from msb...lsb
        ind = (x>>i)&1
        path.append((cur,ind))
        cur = cur.childs[ind]
    cur.cnt -=1
    if cur.cnt==0:
        while path:
            p,i = path.pop()
            p.childs[i] = None
            if p.childs[i^1]: break 
            
def find(root,x):
    cur = root
    for i in range(MX,-1,-1): # store from msb...lsb
        ind = (x>>i)&1
        if not cur.childs[ind]: return 0
        cur = cur.childs[ind]
    return cur.cnt
"""
Find max xor of x in trie
"""
def max_xor(root,x):
    if not root.childs[0] and not root.childs[1]:
        return 0
    cur = root
    for i in range(MX,-1,-1):
        ind = (x>>i)&1
        if cur.childs[ind^1]: cur = cur.childs[ind^1]
        else: cur = cur.childs[ind]
    return cur.val^x

def main():
    n,m = map(int,input().split())
    adj = [[] for i in range(n)]
    for i in range(n-1):
        u,v,w = map(int,input().split())
        u-=1;v-=1;
        adj[u].append((v,w))
        adj[v].append((u,w))
    
    root = Node()
    evroot = Node()
    path = [0]*n
    dd = [0]*n
    def dfs(u,p,xr,d):
        add(root if d else evroot,xr)
        path[u] = xr
        dd[u] = d;
        for v,w in adj[u]:
            if v!=p:
                dfs(v,u,xr^w,(d+1)%2)
    # for x in A: add(root,x)
    dfs(0,-1,0,0)
    # print(path,dd)
    y_ = 0
    for i in range(m):
        ip = input()
        if ip[0]=='^':
            y = int(ip.split(" ")[1])
            y_ ^= y
        else:
            v,x = map(int,ip.split(" ")[1:])
            v -=1
            if dd[v]:
                evroot,root = root,evroot
            remove(evroot,path[v])
            print(max(max_xor(root,x^path[v]^y_),max_xor(evroot,x^path[v])),end=" ")
            add(evroot,path[v])
            if dd[v]:
                evroot,root = root,evroot
    print()
if __name__=='__main__':
    t = int(input())
    while t:
        main()
        t -=1
        
    