class Solution
{
    public int minSwaps(int nums[])
    {
        int n = nums.length;
        int[][] it = new int[n][2];
        for(int i=0;i<nums.length;i++){
            it[i] = new int[]{nums[i],i};
        }
        Arrays.sort(it,(a,b)->a[0]-b[0]);
        int res=0;
        boolean[] vis = new boolean[n];
        for(int i=0;i<nums.length;i++){
            int t = it[i][1];
            vis[i] = true;
            while(!vis[t]){
                res++;
                vis[t] = true;
                t = it[t][1];
            }
        }
        return res;
    }
        // Code here
}