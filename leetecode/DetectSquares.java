import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
// Not Mine
class DetectSquares {
    ArrayList<int[]> al;
    int[][] count;
    public DetectSquares() {
        al = new ArrayList<>();
        count = new int[1001][1001];
    }
    
    public void add(int[] point) { 
        al.add(point);
        count[point[0]][point[1]]++;
    }
    
    public int count(int[] point) {
        int cnt=0;
        for(int[] x:al){
            if(Math.abs(x[0]-point[0])==0 || Math.abs(x[0]-point[0])!=Math.abs(x[1]-point[1])) continue;
            cnt += count[x[0]][point[1]]*count[point[0]][x[1]];
        }
        return cnt;
        
    }
}

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares obj = new DetectSquares();
 * obj.add(point);
 * int param_2 = obj.count(point);
 */