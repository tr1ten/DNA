class Solution:
    def rotateRight(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if(not head or not k): return head;
        ntail=head
        ln = 1
        while(ntail.next): # find tail and length
            ntail = ntail.next
            ln +=1
        if(not (k:=k%ln)): return head # if not shifting
        ntail.next = head # make link list circular
        k = ln-k # position to jump one past starting node of answers
        temp = head 
        while(k>1):
            temp = temp.next
            k -=1
        res = temp.next # store haed
        temp.next = None # break the link of answer tail with its head
        return res