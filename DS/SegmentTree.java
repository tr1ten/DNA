package DS;

public class SegmentTree {
    class Segment{
        int start;
        int end;
        int sum;
        Segment left;
        Segment right;
        Segment(int i,int j,int s){
            this.start = i;
            this.end = j;
            this.sum = s;
        }
        Segment(int i,int j,int s,Segment l,Segment r){
            this(i, j, s);
            left = l;
            right = r;
        }
    }
    Segment root;
    Segment build(int i,int j,int[] nums){
        if(i>j) return null;
        if(i==j) return new Segment(i,j,nums[i]);
        int mid = (i+j)/2;
        Segment left = build(i, mid, nums);
        Segment right = build(mid+1, j, nums);
        return new Segment(i, j,left.sum+right.sum,left,right);
    }
    public SegmentTree(int[] nums){
        root = build(0, nums.length-1, nums);
    }
    private int _recQuery(Segment segment,int l,int r){
        if(segment==null || l>r) return 0;
        if(segment.start==l && segment.end==r) return segment.sum;
        int mid = (segment.start+segment.end)/2;
        return _recQuery(segment.left, l, Math.min(r, mid)) + _recQuery(segment.right, Math.max(mid+1, l), r);
    }
    public int querySum(int l,int r){
        return _recQuery(root, l, r);
    }
    private void _recUpdate(Segment segment,int i,int val){
        if(segment.start==i && segment.end==i) {
            segment.sum = val;
            return;
        }
        int mid = (segment.start+segment.end)/2;
        if(i<=mid) _recUpdate(segment.left, i, val);
        else _recUpdate(segment.right, i, val);
        segment.sum = segment.left.sum + segment.right.sum;

    }
    public void update(int ind,int val){
        _recUpdate(root, ind, val);
    }
    public static void main(String[] args) {
        SegmentTree sg = new SegmentTree(new int[]{1,2,3,4,5,6,7,8,9});
        for (int i = 0; i < 9; i++) {
            sg.update(i, -1);
            System.out.println(sg.querySum(0, i));

        }

    }
}
