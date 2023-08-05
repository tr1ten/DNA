V = 2
MX = 29
class Node:
    def __init__(self) -> None:
        self.childs = [None]*V
        self.ended = False
        self.val = -1
        self.cnt = 0
root = None
def add(x):
    cur = root
    for i in range(MX,-1,-1): # store from msb...lsb
        ind = (x>>i)&1
        if not cur.childs[ind]: cur.childs[ind] = Node()
        cur = cur.childs[ind]
    cur.ended = 1;
    cur.cnt+=1
    cur.val = x
def reset(b):
    global root,MX
    MX  = b
    root = Node()
"""
Find max xor of x in trie
"""
def min_xor(x):
    cur = root
    for i in range(MX,-1,-1):
        if not cur: return float('inf')
        ind = (x>>i)&1
        if cur.childs[ind]: cur = cur.childs[ind]
        else: cur = cur.childs[ind^1]
    return cur.val^x

n = int(input())
A = list(map(int,input().split()))
A.sort() # order doesnt matter
ans = 0
def dnq(l,r,b): # 
    global ans
    if l>=r: return 
    reset(b)
    m = l
    while m<=r and (A[m]&(1<<b))==0: 
        add(A[m])
        m +=1
    if m==l or m>r: 
        dnq(l,r,b-1)
        return 
    xr = float('inf')
    for j in range(m,r+1):
        xr = min(xr,min_xor(A[j]))
    ans += xr if xr<float('inf') else 0
    dnq(l,m-1,b-1)
    dnq(m,r,b-1)

dnq(0,n-1,30)
print(ans)
    