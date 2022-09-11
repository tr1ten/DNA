//  bad solution quadratic
class Solution {
    int _get(int[] mem,int i){
        if(i<0 || i>=mem.length) return 0;
        return mem[i];
    }
    int buy(int idx,int[] prices,int[] mem){
        if(idx>=prices.length) return 0;
        int max = _get(mem,idx+1);
        for(int i=idx+1;i<prices.length;i++){
            max = Math.max(max,prices[i]-prices[idx] + _get(mem,i+2));
        }
        return max;
    }
    public int maxProfit(int[] prices) {
        int n= prices.length;
        int[] mem = new int[n];
        for(int i=n-2;i>=0;i--){
           mem[i] = buy(i,prices,mem); 
        }
        return mem[0];
    }
}