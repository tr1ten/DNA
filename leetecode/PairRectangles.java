import java.util.HashMap;

class Solution {
    public long interchangeableRectangles(int[][] rectangles) {
        HashMap<Double,Integer> hm = new HashMap<>();
        int n = rectangles.length;
        for(int i=0;i<n;i++){
            double ratio = rectangles[i][0]*1.0/rectangles[i][0];
            hm.put(ratio,hm.getOrDefault(ratio,0)+1);
        }
        int cnt=0;
        for(int v:hm.values()){
            cnt +=v;
        }
        return cnt;
    }   
}