A = 2
MX = 32;
class Node:
    def __init__(self) -> None:
        self.childs = [None]*A
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
    cur.val = x

"""
Find max xor of x in trie
"""
def max_xor(x):
    cur = root
    for i in range(MX,-1,-1):
        ind = (x>>i)&1
        if cur.childs[ind^1]: cur = cur.childs[ind^1]
        else: cur = cur.childs[ind]
    return cur.val

def main():
    A = [8,12,9]
    for x in A: add(x)
    print(max_xor(10))

if __name__=='__main__':
    main();