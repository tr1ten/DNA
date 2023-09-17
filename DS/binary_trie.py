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
    cur = root
    for i in range(MX,-1,-1):
        ind = (x>>i)&1
        if cur.childs[ind^1]: cur = cur.childs[ind^1]
        else: cur = cur.childs[ind]
    return cur.val

def main():
    A = [8,12,9]
    root = Node()
    for x in A: add(root,x)
    print(find(root,8))
    # print(max_xor(10)) # 12
    # remove(12)
    # print(max_xor(10)) # 12
    # remove(9)
    # print(max_xor(10)) # 12
    

if __name__=='__main__':
    main();
    