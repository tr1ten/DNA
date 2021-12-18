class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def rec(first, second):
            if(not first and not second):
                return True
            if((not first and second) or (not second and first)):
                return False
            if(first.val != second.val):
                return False
            a = rec(first.left, second.right)
            b = rec(first.right, second.left)
            return (a and b)
        return rec(root.left, root.right)
