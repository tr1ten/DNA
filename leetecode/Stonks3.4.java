import java.util.Arrays;

class Solution {
    public int maxProfit(int k, int[] prices) {
        if(prices.length==1) return 0;
        int[] states = new int[2*k+1];
        Arrays.fill(states, Integer.MIN_VALUE);
        states[0]=0;
        for(int x:prices){
            for(int i=1;i<=2*k;i++){
                states[i] = Math.max(states[i],(i%2==1 ? -x :x) +states[i-1]);
            }

        }
        return Math.max(0,states[2*k]);
    }
}