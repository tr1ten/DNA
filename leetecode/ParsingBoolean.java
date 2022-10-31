import java.util.*;
class Solution {
    HashSet<Character> hs;
    int[] brackets;
    boolean solve(int start,int end,String exp, char lastOp){
        if(end<=start || end>=exp.length()) return true;
        int i=start;
        Stack<Boolean> opd = new Stack<>();
        while (i<=end) {
            char x =exp.charAt(i);
            if(hs.contains(x)){
                opd.push(solve(i+2, brackets[i+1], exp,x));
                i =brackets[i+1];
            }
            if(x=='f' || x=='t') opd.push(x=='t');
            i++;
        }
        if(lastOp=='!') return !opd.pop();
        boolean res=false;
        if(lastOp=='|'){
            res = true;
            while (!opd.isEmpty()) {
                res |= opd.pop();
            }
        }
        else{
            while (!opd.isEmpty()) {
                res &= opd.pop();
            }
        }
        return res;
    
    }
    public boolean parseBoolExpr(String exp) {
        hs = new HashSet<>();
        hs.add('&');
        hs.add('!');
        hs.add('|');
        brackets = new int[exp.length()];
        Stack<Integer> st = new Stack<>();
        for (int i = 0; i < exp.length(); i++) {
            if(exp.charAt(i)=='(') st.push(i);
            if(exp.charAt(i)==')') brackets[st.pop()] = i;
        }
        return solve(0, exp.length()-1, exp, '|');
    }
}