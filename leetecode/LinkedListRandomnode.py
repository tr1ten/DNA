# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
import random
class Solution:
    def __init__(self, head: Optional[ListNode]):
        self.head = head
        self.next = self.head

    def getRandom(self) -> int:
        rand = self.head.val
        temp  = self.head.next
        k = 1 # sample size
        i = 1
        while(temp):
            if(random.randint(1,k+i)==k+i):
                rand = temp.val
            i +=1
            temp = temp.next
        return rand

# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()