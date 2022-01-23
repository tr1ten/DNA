# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
# simple time distance relation (2*slow = fast ) on Tortoise and Hare's method ie distance of start of the cycle is equal from both head and stopped fast pointer 
class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if(not head):
            return None
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if(slow==fast):
                slow = head
                while slow!=fast:
                    slow = slow.next
                    fast = fast.next
                return slow

        return None
            