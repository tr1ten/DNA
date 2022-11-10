class Solution {
    public static int carAssembly(int n, int[][] a, int[][] T, int[] e, int[] x) {
            int N=2; // number of stations
            for(int i=0;i<N;i++){
                a[i][0] += e[i];
                a[i][n-1] += x[i];
            }
            for(int j=n-2;j>=0;j--){
                for(int i=0;i<N;i++){
                    a[i][j] = a[i][j] + Math.min(a[i][j+1],T[i][j+1]+a[(i+1)%N][j+1]); 
                }
            }
            int min = Integer.MAX_VALUE;
            for(int i=0;i<N;i++) min = Math.min(a[i][0],min);
            return min;
    }
}