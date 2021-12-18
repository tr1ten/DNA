class BSTIterator:
    def helper(self, start, transversal):
        if(start):
            self.helper(start.left, transversal)
            transversal.append(start.val)
            self.helper(start.right, transversal)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ls = []
        self.helper(root, ls)
        return ls

    def __init__(self, root: Optional[TreeNode]):
        self.bs = self.inorderTraversal(root)
        self.head = 0

    def next(self) -> int:
        self.head += 1
        return self.bs.pop(0)

    def hasNext(self) -> bool:
        return not (not self.bs)
