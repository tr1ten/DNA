# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        ls = []
        current = head
        while current:
            ls.append(current)
            current = current.next
        if((n+1)>len(ls)):
            if(-n+1>=0):
                return None
            return ls[-n+1]
        if(-n+1>=0):
            ls[-2].next = None
            return head
        ls[-n-1].next = ls[-n].next
        return head