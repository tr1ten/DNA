from sys import stdin,setrecursionlimit
from queue import Queue

setrecursionlimit(10**7)

# Binary tree node class for reference.
# Binary tree node class for reference.
class BinaryTreeNode :
	def __init__(self, data) :
		self.data = data
		self.left = None
		self.right = None
		self.parent = None



def timeToBurnTree(root, start):
	nd = None
	def solve(node,p):
		nonlocal nd;
		if(not node): return;
		node.parent = p
		if(node.data==start):
			nd = node
		solve(node.left,node)
		solve(node.right,node)
	solve(root,None)
	def f(node,p):
		if(not node): return 0
		res = 0
		for child in [node.left,node.right,node.parent]:
			if(child==p): continue
			res = max(res,f(child,node))
		return res+1
	return f(nd,None)-1














# Fast input
def takeInput() :
	
    arr = list(map(int, stdin.readline().strip().split(" ")))

    rootData = arr[0]

    n = len(arr)

    if(rootData == -1) :
        start = int(input().strip())
        return None, start

    root = BinaryTreeNode(rootData)
    q = Queue()
    q.put(root)
    index = 1
    while(q.qsize() > 0) :
        currentNode = q.get()  
        
        leftChild = arr[index]
        
        if(leftChild != -1) :
            leftNode =  BinaryTreeNode(leftChild)  
            currentNode.left = leftNode  
            q.put(leftNode)  
        
        index += 1
        rightChild = arr[index]
        
        if(rightChild != -1) :
            rightNode = BinaryTreeNode(rightChild)
            currentNode .right = rightNode  
            q.put(rightNode)  

        index += 1

    start = int(input().strip())

    return root, start

#main

root, start = takeInput()

print(timeToBurnTree(root, start))