"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

class Solution:
    """
    @param root: the root of binary tree
    @return: new root
    """
    def upside_down_binary_tree(self, root: TreeNode) -> TreeNode:
        def rec(node,par,sibling):
            if not node: return
            rt,lt = node.right ,node.left
            node.left = sibling
            node.right = par
            if not lt: return node
            return rec(lt,node,rt)
        return rec(root,None,None)

