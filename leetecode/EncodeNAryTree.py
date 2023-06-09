from os import *
from sys import *
from collections import *
from math import *

# Binary tree node class for reference:
class BinaryTreeNode:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None
        
        
# Nary tree node class for reference:
class NTreeNode:
    def __init__(self, data):
        self.data = data
        self.child= []

def decode(root):
    def rec(node):
        if not node: return None,None
        gnode = NTreeNode(node.data)
        if not node.left: return gnode,node.right
        leftmost, sibling = rec(node.left)
        if leftmost and leftmost.data!=-1: gnode.child.append(leftmost)
        while(sibling):
            neig,sibling = rec(sibling)
            if neig and neig.data!=-1: gnode.child.append(neig)
        return gnode,node.right
        
    return rec(root)[0]

"""
@param root: N-ary tree
@return: binary tree
"""
def encode(root):
    def rec(gnode,sibling):
        if not gnode: 
            if not sibling: return None
            dummy = BinaryTreeNode(-1)
            dummy.right = sibling
            return dummy
        node=  BinaryTreeNode(gnode.data)
        right = None
        while(gnode.child):
            right = rec(gnode.child.pop(),right)
        node.left = right
        node.right = sibling
        return node
    
    return rec(root,None)