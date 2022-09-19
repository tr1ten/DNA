import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;



class SubstringAllWords {
    public List<Integer> findSubstring(String s, String[] words) {
        HashMap<String,Integer> st = new HashMap<>();
        for (String string : words) {
            st.put(string, st.getOrDefault(string, 0)+1);
        } 
        int ws = words[0].length();
        int p1 = 0;
        int p2 = 0;
        List<Integer> ans = new ArrayList<>();
        HashMap<String,Integer> past = new HashMap<>();
        HashMap<String,Integer> last = new HashMap<>();
        int cnt = 0;
        while (p2+ws<=s.length()) {
            String ss = s.substring(p2,p2+ws);
            if(!st.containsKey(ss)) {
                p1 = p2;
                p2 +=ws;
                cnt=0;
                past.clear();
                last.clear();
                continue;

            }
            cnt++;
            if(past.getOrDefault(ss,0)>=st.getOrDefault(ss, 0)) {
                p1= last.get(ss);
                past.clear();
                last.clear();
                cnt=1;
                continue;
            }
            p2 +=ws;
            past.put(ss,past.getOrDefault(ss, 0)+1);
            if(past.get(ss)==st.get(ss)) last.put(ss, p2-ws);
            if(cnt==words.length){
                ans.add(p1);
                String s2 = s.substring(p1,p1+ws);
                past.put(s2, past.getOrDefault(s2, 0)-1);
                last.remove(s2);
                cnt--;
                p1 +=ws;
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        SubstringAllWords s = new SubstringAllWords();
        String[] words = {"good","best","good","word"};
        String str = "wordgoodgoodgoodbestword";
        System.out.println(s.findSubstring(str, words));
    }
    
}
