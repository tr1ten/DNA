class Solution:
    def helper(self,root):
        if(root):
            root.left,root.right = root.right,root.left
            self.helper(root.left)
            self.helper(root.right)
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.helper(root)
        return root