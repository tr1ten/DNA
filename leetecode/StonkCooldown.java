class Solution {
    public int maxProfit(int[] prices) {
        int[] dph = new int[prices.length+1];
        int[] dpnh = new int[prices.length+1];
        dph[0] = Integer.MIN_VALUE;
        for(int i=0;i<prices.length;i++){
            int x = prices[i];
            dpnh[i+1] = Math.max(dpnh[i],dph[i]+x);
            if(i<1) dph[i+1] = dpnh[i];
            else dph[i+1] = Math.max(dph[i],dpnh[i-1]-x);
        }
        return dpnh[prices.length];  
    }
}