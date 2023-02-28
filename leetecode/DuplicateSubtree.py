# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        id = 0 # unique id for each unique subtree
        cnt = Counter() # cnt number of subtrees associated with single id
        idmap = dict() # store id of triplet (left_id,node val,right_id)
        nodemap = dict() # root node associated with id
        def rec(node):
            nonlocal id
            if(not node): return -1
            left = rec(node.left)
            right = rec(node.right)
            trip = (left,node.val,right)
            if(trip not in idmap): 
                idmap[trip] = id
                nodemap[id] = node
                id +=1
            tid = idmap[trip]
            cnt[tid] +=1
            return tid
        rec(root)
        res = []
        for x in cnt:
            if(cnt[x]>1):
                res.append(nodemap[x])
        return res

