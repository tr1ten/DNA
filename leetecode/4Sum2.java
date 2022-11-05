class Solution {
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        HashMap<Integer,Integer> map = new HashMap<>();
        int res=0;
        for(int x:nums1){
            for(int y:nums2) map.put(x+y,map.getOrDefault(x+y,0)+1);
        }
        for(int x:nums3){
            for(int y:nums4) res += map.getOrDefault(-(x+y),0);
        }
        return res;
    }
}