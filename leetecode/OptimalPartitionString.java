public class OptimalPartitionString {
    public int partitionString(String s) {
        int n = s.length();
        int bm = 0;
        int ans = 1;
        for(int i=0;i<n;i++){
            int k = s.charAt(i) - 'a';
            if((bm & (1<<k))>0){
                ans++;
                bm = 0;
            }
            bm = bm | 1<<k;
        }
    return ans;
    }
}
