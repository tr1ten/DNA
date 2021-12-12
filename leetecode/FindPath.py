# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self,root,targetSum,count):
        if(not root):
            return False
        count +=root.val
        if(not root.left and not root.right):
            if(count==targetSum):
                return True
            return False
        return self.helper(root.left,targetSum,count) or self.helper(root.right,targetSum,count)
    def hasPathSum(self, root, targetSum):
        if(not root):
            return False
        return self.helper(root,targetSum,0)