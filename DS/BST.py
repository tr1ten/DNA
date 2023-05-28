from typing import Iterator
class Node:
    def __init__(self,val:int,left:'Node'=None,right:'Node'=None):
        self.val = val
        self.left = left;
        self.right = right

class BST:
    def __init__(self) -> None:
        self.root = None
    
    def _insert(self,node:Node,val:int):
        if not node: return Node(val)
        if node.val<val: node.left = self._insert(node.left,val)
        else: node.right = self._insert(node.left,val)
        return node
    def _search(self,node:Node,val:int):
        if not node: return None
        if node.val==val: return node
        if node.val<val: return self._search(node.left,val)
        return self._search(node.right,val)
    def _delete(self,node:Node,val:int):
        if not node: return None
        if node.val==val:
            if not node.left: return node.right # handle both case zero or 1 child
            elif not node.right: return node.left
            # node having two child, find next min node 
            temp = node.right
            while(temp.left): temp = temp.left
            node.val,temp.val = temp.val,node.val
            node.right = self._delete(node.right,temp.val)
            return node
            
        if node.val<val: node.left= self._delete(node.left,val)
        else: node.right= self._delete(node.right,val)
        return node
    
    def _inorder(self,node:Node) -> Iterator[int]:
        if not node: return
        yield from self._inorder(node.right) # opposite ordering due to how generator works
        yield node.val
        yield from self._inorder(node.left)
    
    def insert(self,val:int):
        self.root = self._insert(self.root,val)
    
    def search(self,val:int):
        return self._search(self.root,val)

    def delete(self,val:int):
        node = self.search(val)
        if not node:
            raise Exception("No such element")
        self.root = self._delete(self.root,val)
    def inorder(self):
        return self._inorder(self.root)
    
    
# Testing 
def main():
    bst = BST()
    for i in range(10): bst.insert(i+1)
    print(bst.search(10).val) # Found
    bst.delete(10)
    print(bst.search(10)) # Not found
    print(list(bst.inorder())) # [1 2 3 ... N]
    
if __name__=='__main__':
    main()
    

