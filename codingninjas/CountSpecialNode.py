from queue import Queue
from sys import stdin

# Following is the class defined to represent the node of a generic tree
class TreeNode :
    def __init__(self, data) :
        self.data = data
        self.children = list()
        
    def numChildren(self) :
        return len(self.children)
    
    def getChild(self, index) :
        if index > len(self.children) :
            return None
        
        return self.children[index]

def dfs(node,s):
    if(not node): return 0
    res = 0
    if(node.data in s): return 0
    res+=1
    s.add(node.data)
    n = node.numChildren()
    for i in range(n):
        res +=dfs(node.getChild(i),s)
    s.remove(node.data)
    return res
    
    

def countSpecialNodes(root) :   
    return dfs(root,set())



'''----------------Utility Function-----------------'''
def takeInput() :
    data = list(map(int, stdin.readline().strip().split(" ")))
    index = 0
    
    pendingNodes = Queue()
    rootData = data[index]
    index += 1
    
    root = TreeNode(rootData)
    pendingNodes.put(root)
    
    while not pendingNodes.empty() :
        currentNode = pendingNodes.get()
        numChild = data[index]
        index += 1
        
        for i in range(numChild) :
            currenChild = data[index]
            index += 1
            
            childNode = TreeNode(currenChild)
            pendingNodes.put(childNode)
            currentNode.children.append(childNode)
            
    
    return root

#main
t = int(stdin.readline().strip())

while t > 0 :
	
	root = takeInput();
	print(countSpecialNodes(root))

	t -= 1



    