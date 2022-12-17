class Solution {
    int res;
    void solve(ListNode node){
        if(node==null || node.next==null) return;
        int mn = Integer.MAX_VALUE;
        ListNode req = null;
        ListNode dmy = new ListNode();
        dmy.next = node;
        ListNode prev  = dmy;
        while (node!=null && node.next!=null) {
            if(node.val+node.next.val<mn){
                req = prev;
            }
            mn = Math.min(mn, node.val+node.next.val);
            prev = node.next;
            node = node.next.next;
        }
        res+=mn;
        ListNode nnode = new ListNode(mn);
        nnode.next = req.next.next.next;
        req.next = nnode;
        solve(dmy.next);
    }
    public int mctFromLeafValues(int[] arr) {
        ListNode dmy = new ListNode();
        ListNode temp = dmy;
        res = 0;
        for (int x : arr) {
            temp.next = new ListNode(x);
            temp = temp.next;
        }
        solve(dmy.next);
        return res;
    }
}
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