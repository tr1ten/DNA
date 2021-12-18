class Solution:
    def helper(self,start,start2):
        if((start and not start2) or (start2 and not start)):
            return False
        if(start and start2):
            a = self.helper(start.left,start2.left)
            if(start.val!=start2.val):
                return False
            b = self.helper(start.right,start2.right)
            return False if (a is False or b is False) else True
            
            
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        ans = self.helper(p,q)
        return True if ans is None else ans