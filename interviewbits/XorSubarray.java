public class Solution {
    public int solve(int[] A, int B) {
        int xor=0;
        int res =0;
        HashMap<Integer,Integer> hm = new HashMap<>();
        hm.put(0,1);
        for(int i=0;i<A.length;i++){
            xor ^= A[i];
            res += hm.getOrDefault(xor^B,0);
            hm.put(xor,hm.getOrDefault(xor,0)+1);
        }
        return res;
    }
}
