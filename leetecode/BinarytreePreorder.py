# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# O(n) time and 0(n) space
class Solution:
    def preorder_print(self, start, traversal):
        """Helper method - use this to create a 
        recursive print solution."""
        if(not start):
            return
        traversal.append(start.val)
        self.preorder_print(start.left,traversal)
        self.preorder_print(start.right,traversal)
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ls = []
        self.preorder_print(root,ls)
        return ls