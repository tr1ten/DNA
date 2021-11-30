class Solution:
    def reverseList(self, head):
        back = None
        current = head
        while current:
            next_element = current.next
            current.next = back
            back = current 
            current = next_element
        return back
