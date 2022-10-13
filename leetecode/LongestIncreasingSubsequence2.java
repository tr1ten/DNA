class LongesIncreasingSubsequnce2 {
    public int lengthOfLIS(int[] nums, int k) {
        int min=Integer.MAX_VALUE;
        int max=Integer.MIN_VALUE;
        for (int i : nums) {
            min = Math.min(min, i);
            max = Math.max(max, i);
        }
        SegmentTree st = new SegmentTree(min,max);
        int ans=0;
        for (int i = nums.length-1; i >=0; i--) {
            int s = 1 + st.querySum(nums[i]+1, Math.min(nums[i]+k, max));
            ans = Math.max(ans, s);
            st.update(nums[i], s);
        }
        return ans;
    }
    public static void main(String[] args) {
        // [7,4,5,1,8,12,4,7]
        // 5
        int[] nums = {7,4,5,1,8,12,4,7};
        int k = 5;
        LongesIncreasingSubsequnce2 s = new LongesIncreasingSubsequnce2();
        System.out.println(s.lengthOfLIS(nums, k));
    }
}
class SegmentTree {
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
    Segment build(int i,int j){
        if(i>j) return null;
        if(i==j) return new Segment(i,j,0);
        int mid = (i+j)/2;
        Segment left = build(i, mid);
        Segment right = build(mid+1, j);
        return new Segment(i, j,left.sum+right.sum,left,right);
    }
    public SegmentTree(int min,int max){
        root = build(min,max);
    }
    private int _recQuery(Segment segment,int l,int r){
        if(segment==null || l>r) return 0;
        if(segment.start==l && segment.end==r) return segment.sum;
        int mid = (segment.start+segment.end)/2;
        return Math.max(_recQuery(segment.left, l, Math.min(r, mid)), _recQuery(segment.right, Math.max(mid+1, l), r));
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
        segment.sum = Math.max(segment.left.sum, segment.right.sum);

    }
    public void update(int ind,int val){
        _recUpdate(root, ind, val);
    }
}
