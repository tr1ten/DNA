# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructFromPrePost(self, a: List[int], b: List[int]) -> Optional[TreeNode]:
        def build(A,B):
            if not A or not B: return None
            # print(A,B)
            root = TreeNode(A[0])
            assert A[0]==B[-1]
            assert len(A)==len(B)
            if len(A)==1: return root
            if A.index(B[-2])==1:
                root.left =  build(A[1:],B[:-1])
            else:
                l,r = 1,A.index(B[-2])-1
                l1,r1 = 0,B.index(A[1])
                root.left = build(A[l:r+1],B[:r1+1])
                root.right = build(A[r+1:],B[r1+1:-1])
            return root
        return build(a,b)