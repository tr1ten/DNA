class Solution {
    int MOD = 1_000_000_007;
    Integer[][] dp;
    int solve(int idx,int hash,List<List<Integer>> hats,int target){
        if(hash==target) return 1;
        if(idx==40) return 0;
        if(dp[idx][hash]!=null) return dp[idx][hash];
        int res=0;
        for(int h:hats.get(idx)){
            if((hash&(1<<h))==0){
                res = (res+solve(idx+1,hash | (1<<h),hats,target))%MOD;
            }
        }
        return dp[idx][hash]= (res + solve(idx+1,hash,hats,target))%MOD;
    }
    public int numberWays(List<List<Integer>> hats) {
        dp = new Integer[40][(1<<hats.size())];
        List<List<Integer>> rhats = new ArrayList<>();
        for(int i=0;i<40;i++) rhats.add(new ArrayList<>());
        for(int i=0;i<hats.size();i++){
            for(int x:hats.get(i)){
                rhats.get(x-1).add(i);
            }
        }
        int target = (1<<hats.size()) -1;
        return solve(0,0,rhats,target);
    }
}