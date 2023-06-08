#
# @lc app=leetcode id=1803 lang=python3
#
# [1803] Count Pairs With XOR in a Range
#

# @lc code=start
class Node:
    def __init__(self) -> None:
        self.left = None 
        self.right = None
        self.ended = False
class Solution:
    def countPairs(self, A: List[int], low: int, high: int) -> int:
        root = Node()
        MX = 32
        def build(num):
            child = root
            for i in range(MX-1,-1,-1):
                tar = (num &(1<<i)) > 0;
                if tar and not child.right:
                    child.right = Node()
                    child = child.right
                if not tar and not child.left: 
                    child.left = Node()        
                    child = child.left
            child.ended = True
        def query(node,C,K,ind,flag):
            if not node: return 0;
            if node.ended: return 1;
            bc,bk = C&(1<<ind) > 0,K&(1<<ind) > 0
            res = 0
            if bc or bk or flag: # go to 1
                res += query(node.right, C,K,ind-1,flag | (bc and bk and not flag))
            if not (bc and not bk and not flag):  # goto 0
                res += query(node.left, C,K,ind-1,flag | (not bc and bk and not flag))
            return res
        cnt = 0
        for x in A:
            cnt += (query(root,x,high,MX-1,0) - query(root,x,low-1,MX-1,0))
            build(x)
        return cnt
# @lc code=end

