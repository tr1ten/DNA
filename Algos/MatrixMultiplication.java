package Algos;
class Solution{
    static String print(int[][] bt,int i,int j){
        if(j-i<1) return Character.toString((char)('A'+j-1));
        int split = bt[i][j];
        return "(" + print(bt, i, split) + "*" + print(bt, split+1, j)+")";
    }
    static int matrixMultiplication(int N, int arr[])
    {
        int n=N-1;
        int[][] dp = new int[N][N];
        int[][] bt = new int[N][N];
        for(int l=2;l<N;l++){
            for(int i=1;i<=n-(l-1);i++){
                int j = i+l-1;
                int mn = Integer.MAX_VALUE;
                for(int x=i;x<j;x++){
                    int temp = dp[i][x] + dp[x+1][j] + arr[i-1]*arr[x]*arr[j];
                    if(mn>temp){
                        mn = temp;
                        bt[i][j] = x;
                    }

                }
                dp[i][j] = mn;
            }
        }
        // printing solution
        System.out.println(print(bt, 1, N-1));
        return dp[1][n];
    }
    public static void main(String[] args) {
        int N = 4;
        int[] arr = {10, 30, 5, 60};
        System.out.println(matrixMultiplication(N, arr));
    }
}