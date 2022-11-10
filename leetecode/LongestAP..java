class Solution {
    public int longestArithSeqLength(int[] nums) {
        int n = nums.length;
        HashMap<Integer,Integer>[] maps = new HashMap[n];
        int res=0;
        for(int i=0;i<n;i++) maps[i] = new HashMap<>();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                    int d = nums[j]-nums[i];
                    maps[j].put(d,maps[i].getOrDefault(d,1)+1);
                    res = Math.max(res,maps[j].get(d));
            }
        }
        return res;
    }
}