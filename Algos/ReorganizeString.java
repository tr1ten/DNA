import java.util.Arrays;

class Solution {
    char[] res;
    boolean solve(int idx,int[][] cnt){
        if(idx==res.length) return true;
        for(int i=0;i<26;i++){
            if(cnt[i][1]>0 && (idx==0 || (res[idx-1]-'a')!=cnt[i][0])){
                cnt[i][1]--;
                res[idx] = (char)('a'+cnt[i][0]);
                if(solve(idx+1,cnt)) return true;
                cnt[i][1]++;
            }
        }
        return false;
    }
    public String reorganizeString(String s) {
        int n = s.length();
        res = new char[n];
        int[][] cnt = new int[26][2];
        for(char x:s.toCharArray()) {
            cnt[x-'a'][0] = x-'a';
            cnt[x-'a'][1]++;
        }
        Arrays.sort(cnt,(a,b)->b[1]-a[1]);
        boolean r = solve(0,cnt);
        System.out.println(Arrays.deepToString(cnt));
        return r ? String.valueOf(res) : "";
    }
}