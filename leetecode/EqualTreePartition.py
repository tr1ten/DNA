from lintcode import (
    TreeNode,
)

"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""
from collections import Counter
class Solution:
    """
    @param root: a TreeNode
    @return: return a boolean
    """
    def check_equal_tree(self, root: TreeNode) -> bool:
        sums = Counter()
        def rec(node):
            if not node: return 0
            sm = rec(node.left) + rec(node.right) + node.val
            sums[sm] +=1
            return sm
        sm = rec(root)
        tar = sm//2
        if sm%2==1 or sums[tar]==0: return False
        if tar==0 and sums[tar]<=1: return False
        return True

