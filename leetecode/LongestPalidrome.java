import java.util.HashMap;

class Solution {
    public int longestPalindrome(String[] words) {
        HashMap<String,Integer> opp = new HashMap<>();
        int cnt=0;
        for(String word:words){
            String r = word.charAt(1)+""+word.charAt(0);
                if(opp.getOrDefault(r,0)>0) {
                    cnt++;
                    opp.put(r,opp.get(r)-1);
                }
                else opp.put(word,opp.getOrDefault(word,0)+1);
        }
        int res=cnt*4;
        for (String key : opp.keySet()) {
            String r = key.charAt(1)+""+key.charAt(0);
            if(r.equals(key)){
                res +=2;
                break;
            }
        }
        return res;
    }
}