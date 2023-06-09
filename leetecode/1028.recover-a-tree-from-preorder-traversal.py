# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverFromPreorder(self, tr: str) -> Optional[TreeNode]:
        st = [] # this will keep path till node
        i = 0
        while(i<len(tr)):
            level = 0
            while(tr[i]=='-'): 
                level +=1
                i +=1
            num = ""
            while(i<len(tr) and tr[i].isdigit()):
                num +=tr[i]
                i +=1
            node = TreeNode(num)
            while(len(st)>level):
                st.pop()
            if st:
                if not st[-1].left:
                    st[-1].left = node
                else:
                    st[-1].right = node
            st.append(node)
        return st[0]

            
        