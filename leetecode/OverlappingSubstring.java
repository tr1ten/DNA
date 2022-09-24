import java.util.ArrayList;
import java.util.Currency;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Stack;

// freakin hard one
class OverlappingSubstring {
    private int getEnd(ArrayList<int[]> intervals,int i,String s,HashMap<Character,Integer> hm){
        int end = intervals.get(hm.get(s.charAt(i)))[1];
        for(int j=i+1;j<end;j++){
            if(intervals.get(hm.get(s.charAt(j)))[0]<i ){
                return -1;
            }
            end = Math.max(end,intervals.get(hm.get(s.charAt(j)))[1]);

        }
        return end;
    }
    // two phases
    // first get first and last occurences of each character stored in some form 
    // now check for each character if they form valid substring
    public List<String> maxNumOfSubstrings(String s) {
        List<String> res = new ArrayList<>();
        if(s.length()==0) return res;
        ArrayList<int[]> intervals = new ArrayList<>();
        int cnt =0;
        HashMap<Character,Integer> hm = new HashMap<>();
        // overly complicated just use two arrays of left and right 
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if(!hm.containsKey(c)){
                hm.put(c, cnt);
                intervals.add(new int[]{i,i});
                cnt++;
            }
            else{
                int[] interval = intervals.get(hm.get(c));
                interval[1] = i;
            }
        }
        int right = -1;
        for (int i = 0; i < s.length(); i++) {
            if(i==intervals.get(hm.get(s.charAt(i)))[0]){
                int end = getEnd(intervals,i,s,hm);
                // if there is previous occurence of some in substring
                if(end!=-1){
                    // if new right is greator then prev substring right then it is correct else replace it
                    if(right<end){
                        res.add("");
                    }
                    right = end;
                    res.set(res.size()-1, s.substring(i, end+1));
                }
            }
        }
        return res;

    }
    public static void main(String[] args) {
        var sol = new OverlappingSubstring();
        System.out.println(sol.maxNumOfSubstrings("tdzbsjgnmfcocyzxnxzcj"));
    }
}