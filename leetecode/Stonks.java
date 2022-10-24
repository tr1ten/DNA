// since most of them are similar, this is generic code for stocks problem on leetcode
class Solution {
    public int maxProfit(int[] prices) {
        int nh = 0,h=Integer.MIN_VALUE;
        for(int x:prices){
            int prev_nh = nh;
            nh = Math.max(nh,h+x);
            h = Math.max(h,prev_nh-x);
        }
        return nh;
    }
}