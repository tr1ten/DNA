class Solution {
    public int longestIdealString(String s, int k) {
     int[] cnt = new int[26];
     int n = s.length();
     int[] vals  = new int[n];
     for(int i=0;i<n;i++){
         for(int j=0;j<26;j++){
             if(Math.abs(j-(s.charAt(i)-'a'))<=k) vals[i] +=cnt[j];
         }
         cnt[s.charAt(i)-'a'] = vals[i]+1;
     }
     StringBuilder sb = new StringBuilder();
     

 }
}