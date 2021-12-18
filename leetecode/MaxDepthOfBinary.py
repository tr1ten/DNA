class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if(not root):
            return 0

        def rec(start, count=1):
            if(not start):
                return count - 1
            return max(rec(start.left, count+1), rec(start.right, count+1))
        return rec(root, 1)
