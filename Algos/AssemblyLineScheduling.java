package Algos;
class Solution {
    public static int carAssembly(int n, int[][] a, int[][] T, int[] e, int[] x) {
            int N=2; // number of stations
            for(int i=0;i<N;i++){
                a[i][0] += e[i];
                a[i][n-1] += x[i];
            }
            // for printing the path
            int[][] bt = new int[N][n];
            for(int j=n-2;j>=0;j--){
                for(int i=0;i<N;i++){
                    // a[i][j] = a[i][j] + Math.min(a[i][j+1],T[i][j+1]+a[(i+1)%N][j+1]);
                    if(a[i][j+1] < T[i][j+1]+a[(i+1)%N][j+1]){
                        a[i][j] = a[i][j] + a[i][j+1];
                        bt[i][j] = i;
                    }
                    else{
                        a[i][j] = a[i][j] + T[i][j+1]+a[(i+1)%N][j+1];
                        bt[i][j] = (i+1)%N;
                    }
            }
            }
            // backtracking solution
            int min = Math.min(a[0][0],a[1][0]);
            int i = (a[0][0] < a[1][0])?0:1;
            System.out.println("Path taken:");
            System.out.print((i+1)+"->");
            for(int j=0;j<n-1;j++){
                i = bt[i][j];
                System.out.print((i+1)+"->");
            }
            return min;
    }
    public static void main(String[] args) {
        int n = 4;
        int[][] a = {{4, 5, 3, 2},
                     {2, 10, 1, 4}};
        int[][] t = {{0, 7, 4, 5},
                     {0, 9, 2, 8}};
        int[] e = {10, 12}, x = {18, 7};
        System.out.println("\n"+carAssembly(n, a, t, e, x));
    }
}