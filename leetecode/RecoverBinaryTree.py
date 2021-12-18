# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, start, transversal):
        if(start):
            self.helper(start.left, transversal)
            transversal.append(start)
            self.helper(start.right, transversal)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ls = []
        self.helper(root, ls)
        return ls

    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        sortedArr = self.inorderTraversal(root)
        first = None
        mid = None
        last = None
        for i in range(len(sortedArr)):
            if((first or mid) and sortedArr[i].val < sortedArr[i-1].val):
                last = sortedArr[i]
                break
            if(i > 0 and sortedArr[i].val < sortedArr[i-1].val):
                first = sortedArr[i-1]
                mid = sortedArr[i]
        if(first and last):
            first.val, last.val = last.val, first.val
        else:
            first.val, mid.val = mid.val, first.val
        return root
