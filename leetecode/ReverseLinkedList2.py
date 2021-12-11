class Solution(object):
    def reverseBetween(self, head, left, right):
        """
        :type head: ListNode
        :type left: int
        :type right: int
        :rtype: ListNode
        """
        start = ListNode(0,head)
        lastNode = start
        cur = start.next
        for i in range(left-1):
            lastNode = cur
            cur = cur.next
        prev = None
        for i in range(right-left+1):
            temp = cur.next
            cur.next = prev
            prev = cur
            cur = temp
        lastNode.next.next = cur 
        lastNode.next = prev
        return start.next