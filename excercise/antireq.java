package excercise;

import java.util.Arrays;

class antireq {
    static int solve(int n,int[][] intervals ){
        Arrays.sort(intervals,(a,b)->a[0]-b[0] );
        int res = 0;
        int temp = 0;
        int end = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if(intervals[i][0]<=end){
                temp++;
            }
            else{
                res = Math.max(res, temp);
                temp = 0;
                end = intervals[i][1];
            }
        }
        return Math.max(temp, res);
    }
    public static void main(String[] args) {
        int[][] arr = {{1,3},{2,5},{2,4},{3,5}};
        System.out.println(solve(4,arr));
        
    }  
}
