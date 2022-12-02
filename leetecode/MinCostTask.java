class Solution {
    public int minimumRounds(int[] tasks) {
        HashMap<Integer,Integer> map = new HashMap<>();
        for(int x:tasks) map.put(x,map.getOrDefault(x,0)+1);
        int res = 0;
        for(int k:map.keySet()){
            int val = map.get(k);
            if(val==1) return -1;
            if((val%3)%2==0){
                res += val/3;
                val = val - 3*(val/3);
            }
            res +=val/2;
        }
        return res;
    }
}