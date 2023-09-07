A = 2
MX = 32;
class Node:
    def __init__(self) -> None:
        self.childs = [None]*A
        self.ended = False
        self.val = -1
        self.cnt = 0
root = Node()
def add(x):
    cur = root
    for i in range(MX,-1,-1): # store from msb...lsb
        ind = (x>>i)&1
        if not cur.childs[ind]: cur.childs[ind] = Node()
        cur = cur.childs[ind]
    cur.ended = 1;
    cur.cnt+=1
    cur.val = x

def remove(x):
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
"""
Find max xor of x in trie
"""
def max_xor(x):
    cur = root
    for i in range(MX,-1,-1):
        ind = (x>>i)&1
        if cur.childs[ind^1]: cur = cur.childs[ind^1]
        else: cur = cur.childs[ind]
    return cur.val^x

n = int(input())
add(0)
for i in range(n):
    t,x = input().split()
    x = int(x)
    if t=='+':
        add(x)
    elif t=="-":
        remove(x)
    else:
        print(max_xor(x))