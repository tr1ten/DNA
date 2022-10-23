import java.util.HashMap;
import java.util.Stack;

class Solution {
    HashMap<Integer,Integer> map;
    int solve(String s,int start,int end){
        int mx =0;
        int i = start;
        while (i<=end) {
            if(map.containsKey(i)){
                mx = Math.max(mx, 1+solve(s, i+1, map.get(i)-1));
                i = map.get(i);
            }
            i++;
        }
        return mx;
    }
    public int maxDepth(String s) {
        Stack<Integer> st  =new Stack<>();
        map = new HashMap<>();
        for (int i=0;i<s.length();i++) {
            char x=s.charAt(i);
            if(x=='(') st.push(i);
            else if(x==')') map.put(st.pop(), i);
        }
        return solve(s, 0, s.length()-1);
    }
}