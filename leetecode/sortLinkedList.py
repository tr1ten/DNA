# Definition for singly-linked list.
from ast import main


class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
"""Using merge sort"""
class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if(not head or not head.next):
            return head
        left = head
        right = self.getmid(left)
        temp = right.next
        right.next = None
        right = temp
        left = self.sortList(left)
        right = self.sortList(right)
        return self.merge(left,right)
    def merge(self,left,right):
        temp = tail = ListNode()
        while left and right:
            if(left.val<right.val):
                tail.next = left
                left = left.next
            else:
                tail.next = right
                right = right.next
            tail = tail.next
        if(left):
            tail.next = left
        if(right):
            tail.next = right
        return temp.next
    def getmid(self,head):
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        return slow

def main():
    head = ListNode(4)
    head.next = ListNode(2)
    head.next.next = ListNode(1)
    head.next.next.next = ListNode(3)
    head = Solution().sortList(head)
    while head:
        print(head.val)
        head = head.next
        
main()