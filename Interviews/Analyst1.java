package Interviews;

import java.util.Arrays;

public class Analyst1 {
    static long[] Find_Max_Coordinate(long[] x,long[] y){
        int n = x.length;
        long[][] ivals = new long[n][2];
        for (int i = 0; i < n; i++) {
            ivals[i] = new long[]{x[i],y[i]};
        }
        Arrays.sort(ivals,(a,b)->Long.compare(a[0], b[0])); 
        long[] res = new long[n];
        for(int i=n-1;i>=0;i--){
            long end = ivals[i][0]+ivals[i][1];
            long mx = end;
            for (int j = i+1; j < n; j++) {
                if(ivals[j][0]>end) break;
                mx = Math.max(mx, res[j]);
            }
            res[i] = mx;
        }
        return res;
    }
    public static void main(String[] args) {
        long[] x = {5,6,9,11,12,16,20};
        long[] y = {2,3,1,5,3,1,1};
        System.out.println(Arrays.toString(Find_Max_Coordinate(x, y)));


    }
}
