class Solution{
    static private int N = 10_000_0;
    static private int[] sieve;
    static void compute(){
        for(int i=2;i<=N;i++){
            if(sieve[i]!=0) continue;
            for(int j=2*i;j<=N;j +=i){
                sieve[j] = i;
            }
        }
    }
    {
        sieve = new int[N+1];
        compute();
    }
    static long largestPrimeFactor(int N) {
        if(sieve[N]!=0) return sieve[N];
        else return N;
    }
}