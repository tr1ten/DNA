class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }

    ListNode(int x, ListNode next) {
        val = x;
        this.next = next;
    }
}

public class RemoveNthNode {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode nhead = new ListNode(0);
        nhead.next = head;
        ListNode first = nhead;
        ListNode second = head;
        while(n>0)
        {
            second = second.next;
            n--;
        }
        while (second!=null) {
            second = second.next;
            first = first.next;
        }
        first.next = first.next.next;
        return nhead.next;
    }   
}
