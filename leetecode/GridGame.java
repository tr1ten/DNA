class Solution {
    public long gridGame(int[][] grid) {
        int n = grid[0].length;
        long[] prefix = new long[n];
        long[] prefix2 = new long[n];
        prefix[0] = grid[0][0];
        prefix2[0] = grid[1][0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + grid[0][i]; 
            prefix2[i] = prefix2[i-1] + grid[1][i]; 

        }
        long min = Long.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            min = Math.min(min, Math.max(prefix[n-1]-prefix[i], i==0 ? 0 : prefix2[i-1] ));
        }

        return min;
    }
}