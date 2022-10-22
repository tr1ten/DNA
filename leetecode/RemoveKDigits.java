import java.util.*;
class Solution {
    public String removeKdigits(String num, int k) {
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < num.length(); i++) {
            while(k>0 && !st.isEmpty() && st.peek()>num.charAt(i)){
                st.pop();
                k--;
            }
            if(st.isEmpty() || num.charAt(i)!='0'){
                st.push(num.charAt(i));
            }
        }
        StringBuilder sb = new StringBuilder();
        for (Character character : st) {
            sb.append(character);
        }
        if(k!=0) {
            return sb.substring(0,sb.length()-k);
        }
        return sb.toString();
        
    }
}