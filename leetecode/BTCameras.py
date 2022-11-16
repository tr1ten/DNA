
class Solution:
    def minCameraCover(self, root: TreeNode) -> int:
        def solve(root,cam,mcam):
            if root == None:
                return 1001 if mcam else 0
            res = solve(root.left,True,False) + solve(root.right,True,False) + 1
            if mcam:
                return res
            res = min(solve(root.left,False,not cam)+solve(root.right,False,False),res)
            if not cam:
                res = min(solve(root.right,False,not cam)+solve(root.left,False,False),res)
            return res
        if root.left == None and root.right == None:
            return 1
        return min(solve(root,False,True),solve(root,False,False))
    