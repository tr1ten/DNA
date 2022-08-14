

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}
// or use priority queue with complexity NlogN, N-nodes
public class MergeKLL {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode dummyhead = new ListNode();
        var temp = dummyhead;
        while (true){
            int min = Integer.MAX_VALUE;
            int minInd = -1;
            for (int i = 0; i < lists.length; i++) {
                if(lists[i]!=null && lists[i].val<min){
                    minInd = i;
                    min = lists[i].val;
                }
            }
            if(min==Integer.MAX_VALUE) break;
            temp.next = new ListNode(min);
            temp = temp.next;
            lists[minInd] = lists[minInd].next;
        }
        return dummyhead.next;
    }
}
