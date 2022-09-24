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
        int mx_size = ws*words.length;
        List<Integer> ans = new ArrayList<>();
        for (int i = 0; i < s.length()-mx_size; i++) {
            String ss = s.substring(i,i+mx_size);
            HashMap<String,Integer> seen = new HashMap<>();
            boolean fl= true;
            for (int j = 0; j < mx_size; j +=ws) {
                    String sub = ss.substring(j,j+ws);
                    seen.put(sub, seen.getOrDefault(sub, 0)+1);
                    if(seen.get(sub)>st.getOrDefault(sub, 0)) {
                        fl = false;
                        break;
                    }
                } 
                if(fl) ans.add(i);            
        }
        return ans;
    }
    public static void main(String[] args) {
        SubstringAllWords s = new SubstringAllWords();
        String[] words = { "aa", "aa" };
        String str = "aaaaaaaa";
        System.out.println(s.findSubstring(str, words));
    }
    
}
