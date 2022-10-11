class Solution {
    int minSum(int[] nums,int k){
        int sum = 0;
        for(int i = 0;i < k;i++){
            sum += nums[i];
        }
        int min = sum;
        int start = 0;
        int p=k;
        for(int i = k;i < nums.length;i++){
            sum = sum - nums[start] + nums[p];
            min = Math.min(min,sum);
            start++;
            p++;
        }
        return min;
    }
    public int maxScore(int[] cardPoints, int k) {
        int sum=0;
        for(int i=0;i<cardPoints.length;i++) {
            sum+=cardPoints[i];
        }
        return sum-minSum(cardPoints, k);

    }
    
}