class Solution:
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        def solve(start,end):
            if(start==end): return None
            if(start.next==end): TreeNode(start.val)
            slow=fast=start
            while(fast!=end and fast.next!=end):
                slow = slow.next
                fast=fast.next.next
            left = solve(start,slow)
            right = solve(slow.next,end)
            root = TreeNode(slow.val)
            root.left,root.right = left,right
            return root
        return solve(head,None)