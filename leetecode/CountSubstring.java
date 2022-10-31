class Solution {
    public int countSubstrings(String s, String t) {
        int n = s.length();
        int m = t.length();
        int res=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(s.charAt(i)==t.charAt(j)) continue;
                int left = 0;
                int right = 0;
                while (i-left>=0 && j-left>=0 && s.charAt(i-left)==t.charAt(j-left)) left++;
                while (i+right<n && j+right<m && s.charAt(i+right)==t.charAt(j+right)) right++;
                res += left*right;
            }
        }
        return res;
    }
}