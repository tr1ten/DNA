# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self,start,transversal):
        if(start):
            self.helper(start.left,transversal)
            self.helper(start.right,transversal)
            transversal.append(start.val)
            
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ls = []
        self.helper(root,ls)
        return ls
    