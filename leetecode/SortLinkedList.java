
class SortedLinkedList {
    ListNode merge(ListNode head1,ListNode head2){
        if(head1==null) return head2;
        if(head2==null) return head1;
        ListNode dh = new ListNode(0);
        ListNode temp = dh;
        while (head1!=null && head2!=null) {
            if(head1.val<head2.val) {
                temp.next = head1;
                head1 = head1.next;
            }
            else{
                temp.next = head2;
                head2 = head2.next;
            }
            temp = temp.next;
        }
        if(head1==null) temp.next = head2;
            if(head2==null) temp.next = head1;
            
        return dh.next;
    }
    ListNode mergeSort(ListNode head){
        if(head==null || head.next==null) return head;
        ListNode mid = getMid(head);
        ListNode right = mid.next;
        mid.next = null;
        ListNode hleft = mergeSort(head);
        ListNode hright = mergeSort(right);
        return merge(hleft, hright);
    }
    public ListNode sortList(ListNode head) {
        return mergeSort(head);
    }
    ListNode getMid(ListNode head){
        if(head==null) return null;
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast!=null && fast.next!=null) {
            fast = fast.next.next;
            slow = slow.next;
        }
        return slow;
    }
    public static void main(String[] args) {
        SortedLinkedList obj = new SortedLinkedList();
        ListNode root = new ListNode(10);
        root.next = new ListNode(4);
        root.next.next = new ListNode(3);
        root.next.next.next = new ListNode(4);
        root.next.next.next.next = new ListNode(20);
        ListNode pt = obj.sortList(root);
        while (pt!=null) {
            System.out.print(pt.val+" ");
            pt = pt.next;
        }
    }
}