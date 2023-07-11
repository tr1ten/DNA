n = int(input())
A = list(map(int,input().split()))
MX = 16;
class Node:
    A = 2
    def __init__(self) -> None:
        self.childs = [None]*self.A
        self.ended = False
        self.val = -1
root = Node()
def add(x):
    cur = root
    for i in range(MX,-1,-1): # store from msb...lsb
        ind = (x>>i)&1
        if not cur.childs[ind]: cur.childs[ind] = Node()
        cur = cur.childs[ind]
    cur.ended = 1;
    cur.val = x;

"""
Find max xor of x in trie
"""
def max_query(x):
    cur = root
    for i in range(MX,-1,-1):
        ind = (x>>i)&1
        if cur.childs[ind^1]: cur = cur.childs[ind^1]
        else: cur = cur.childs[ind]
    return cur.val

res = 0
for i in range(n):
    sms = []
    sm = 0
    for j in range(i,n):
        sm +=A[j]
        sms.append(sm);
        if i>0: res = max(res,max_query(sm)^sm)
    sm = 0
    for j in range(i,-1,-1):
        sm += A[j]
        add(sm)
print(res)
        