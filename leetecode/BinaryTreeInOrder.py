class Solution:
    def helper(self,start,transversal):
        if(start):
            self.helper(start.left,transversal)
            transversal.append(start.val)
            self.helper(start.right,transversal)
            
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ls = []
        self.helper(root,ls)
        return ls
    