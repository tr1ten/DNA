class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if(not head or not head.next):
            return head
        b = head
        f = b.next
        while f:
            f.val, b.val = b.val, f.val
            b = f.next
            if(not b):
                break
            f = b.next
        return head
