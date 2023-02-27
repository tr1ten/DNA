package DS;

// Similar to Segment Tree, but with a different implementation and more efficient for range sum queries
public class FenwickTree {
    int[] tree;
    FenwickTree(int[] nums){
        tree = new int[nums.length+1];
    }
    void update(int i,int diff){
        i++; // need position rather than index
        while (i<tree.length) {
            tree[i] +=diff;
            i += (i&(-i)); // get next position to update by removing last 1 bit 110 -> 10 or 11010100 -> 100
        }
    }
    int rangeSum(int i){
        i++;
        int sum=0;
        while (i>0) {
            sum += tree[i];
            i -= (i&(-i)); // maintain the last 1 bit
        }
        return sum;
    }
    int rangeSum(int i,int j){
        return rangeSum(j)-rangeSum(i-1);
    }
    public static void main(String[] args) {
        int[] nums = {1,2,3,4,5,6,7,8,9,10};
        FenwickTree ft = new FenwickTree(nums);
        for (int i = 0; i < nums.length; i++) {
            ft.update(i, nums[i]);
        }
        System.out.println(ft.rangeSum(2, 2));
    }
}
