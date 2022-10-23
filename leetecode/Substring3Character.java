class Solution {
    public int numberOfSubstrings(String s) {
        int[] cnt = new int[3];
        int j = 0;
        int res = 0;
        for(int i=0;i<s.length();i++){
            cnt[s.charAt(i)-'a']++;
            if(cnt[0]>0 && cnt[1]>0 && cnt[2]>0){
                int left =0;
                while(j<i && cnt[0]>0 && cnt[1]>0 && cnt[2]>0){
                    left++;
                    cnt[s.charAt(j)-'a']--;
                    j++;
                }
                res += (s.length()-i)*(left);
            }
        }
        return res;
    }
}