class Solution{
    static String print(int[][] bt,int i,int j){
        if(j-i<=1) return Character.toString((char)('A'+j-1));
        int split = bt[i][j];
        return "(" + print(bt, i, split) + "*" + print(bt, split, j)+")";
    }
    static int matrixMultiplication(int N, int arr[])
    {
        int[][] dp = new int[N][N];
        int[][] bt = new int[N][N];
        for(int i=2;i<N;i++){
            for(int j=0;j+i<N;j++){
                int k = j+i;
                int mn = Integer.MAX_VALUE;
                for(int x=j+1;x<k;x++){
                    int temp = dp[j][x] + dp[x][k] + arr[j]*arr[k]*arr[x];
                    if(mn>temp){
                        mn = temp;
                        bt[j][k] = x;
                    }

                }
                dp[j][k] = mn;
            }
        }
        // printing solution
        System.out.println(print(bt, 0, N-1));
        return dp[0][N-1];
    }
    public static void main(String[] args) {
        int N = 7;
        int[] arr = {30,35,15,5,10,20,25};
        matrixMultiplication(N, arr);
    }
}