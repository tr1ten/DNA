class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        nodes = [root]
        ans = []
        while root and nodes:
            nextNodes = []
            ans.append([])
            for node in nodes:
                ans[-1].append(node.val)
                if(node.left):
                    nextNodes.append(node.left)
                if(node.right):
                    nextNodes.append(node.right)
            nodes = nextNodes
        return ans
