package Algos;

public class RMQ {
    int[][] m;
    RMQ(int[] arr){
        // preprocessing
        int N = arr.length;
        int LOG = (int)Math.floor((Math.log(N)/Math.log(2)));
        m = new int[N][LOG];
        for (int i = 0; i < N; i++) m[i][0] = arr[i];
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < N-(1<<j)+1; i++) m[i][j] = Math.min(m[i][j-1], m[i+(1<<(j-1))][j-1]);
        }

    }
    int query(int L,int R){
        int len = R-L+1;
        int j = (int)Math.floor((Math.log(len)/Math.log(2)));
        return Math.min(m[L][j], m[R-(1<<j)+1][j]);
    }
    public static void main(String[] args) {
        // testing
        int[] arr = {5,4,3,1,2,3,4};
        RMQ rmq = new RMQ(arr);
        System.out.println(rmq.query(2, 2));
        
    }
}
