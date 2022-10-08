class Solution {
    public List<Integer> goodDaysToRobBank(int[] nums, int time) {
        int n = nums.length;
        boolean[] front = new boolean[n];
        front[0] = time==0;
        int sz=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>=nums[i]) sz++;
            else sz = 0;
            front[i] = sz>=time;
        }
        boolean[] back = new boolean[n];
        back[n-1] = time==0;
        sz=0;
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]>=nums[i]) sz++;
            else sz = 0;
            back[i] = sz>=time;
        }
        List<Integer> ls = new ArrayList<Integer>();
        for(int i=0;i<n;i++){
            if(back[i] && front[i]) ls.add(i);
        }
        return ls;
    }
}