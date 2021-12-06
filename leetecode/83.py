# remove duplicate from sorted LL
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        prevNode = None;
        curr  = head
        while curr:
            if(prevNode and curr.val==prevNode.val):
                prevNode.next = curr.next
            else:
                prevNode = curr
            curr = prevNode.next
        return head
        