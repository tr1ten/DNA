class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

class BinaryTree(object):
    def __init__(self, root):
        self.root = Node(root)
    def binaryInsert(self,value):
        self.preorderBinaryInsert(self.root,value) 
    def preorderBinaryInsert(self,start,value):
        if(start.value>value):
            if(not start.left):
                start.left = Node(value)
            else:
                self.preorderBinaryInsert(start.left,value)
        else:
            if(not start.right):
                start.right = Node(value)
            else:
                self.preorderBinaryInsert(start.right,value)
        
    def binarySearch(self,find_val):
        return self.preorderBinarySearch(self.root,find_val)
    def preorderBinarySearch(self,start,val):
        if(not start):
            return False
        if(start.value == val):
            return True
        if(val>start.value):
            return self.preorderBinarySearch(start.right,val)
        return self.preorderBinarySearch(start.left,val)
    def search(self, find_val):
        """Return True if the value
        is in the tree, return
        False otherwise."""
        return self.preorder_search(self.root,find_val)

    def print_tree(self):
        """Print out all tree nodes
        as they are visited in
        a pre-order traversal."""
        ls = []
        self.preorder_print(self.root,ls)
        return "-".join([str(i) for i in ls])

    def preorder_search(self, start, find_val):
        """Helper method - use this to create a 
        recursive search solution."""
        if(start.value == find_val):
            return True
        if not (start.left or start.right):
            return False
        
        return self.preorder_search(start.left,find_val) or self.preorder_search(start.right,find_val)

    def preorder_print(self, start, traversal):
        """Helper method - use this to create a 
        recursive print solution."""
        if(not start):
            return
        traversal.append(start.value)
        self.preorder_print(start.left,traversal)
        self.preorder_print(start.right,traversal)


# Set up tree
# Set up tree
tree = BinaryTree(4)

# Insert elements
tree.binaryInsert(2)
tree.binaryInsert(1)
tree.binaryInsert(3)
tree.binaryInsert(5)
# Test search
# Should be True
print(tree.search(5))
# Should be False
print(tree.search(6))

# Test print_tree
# Should be 1-2-4-5-3
print(tree.print_tree())