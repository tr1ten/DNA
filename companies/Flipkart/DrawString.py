A = 28
class Node():
    def __init__(self):
        self.childs= [None]*A
        self.ended = False
        self.w = None
n = int(input())
def tr(x): return x.replace('o','{').replace('a','{').replace('l','|').replace('t','|') 
S = tr(input())
s = S
T = list(map(
    tr,
    input().split()))
K = int(input())
root = Node()
def build(w):
    child = root
    for x in w:
        ind = ord(x) - ord('a')
        if not child.childs[ind]: child.childs[ind] = Node()
        child = child.childs[ind]
    child.ended = True
    child.w = w
    
for w in T:
    build(w)
def solve(node,idx,k,chance):
    res= node.ended
    node.ended = False # don't count repeated match tickets
    if chance: # try skipping character from ticket
        for i in range(26):
            if node.childs[i]: res += solve(node.childs[i],idx,k,False)
    if idx>=len(s):return res
    if k>0: res += solve(node,idx+1,k-1,chance) # skip idx of draw 
    ind = ord(s[idx]) - ord('a')
    if node.childs[ind]: res += solve(node.childs[ind],idx+1,k,chance) # take it
    return res
res = 0

for i in range(len(S)-1):
    s = s[1:]
    res += solve(root,0,K,True)
print(res)