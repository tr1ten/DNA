import java.util.Stack;

class Solution {
    private int getInt(String s, int idx){
        if(idx<0 | idx>=s.length()) return -1;
        int c =  s.charAt(idx) - '0';
        if(c>=0 && c<=9) return c;
        return -1;

    }
    public int myAtoi(String s) {
        long ts = 0;
        int st=0;
        // get rid of all leading spaces
        while (st<s.length() && s.charAt(st)==' ') st++;
        boolean isNeg = false;
        if( st<s.length() && (s.charAt(st)=='-' || s.charAt(st)=='+')) {
                        isNeg = s.charAt(st)=='-';
            st++;
        }
        Stack<Integer> stack = new Stack<>();
        int nx = getInt(s, st++);
        while(nx!=-1) {
            stack.push(nx);
            nx = getInt(s, st++);
        }
        int i=0;
        while(!stack.isEmpty()){
            ts += Math.pow(10,i++)*stack.pop();
            if((ts>=Integer.MAX_VALUE && !isNeg) || (ts>Integer.MAX_VALUE && isNeg)) {
                ts= isNeg ? Integer.MAX_VALUE + 1: Integer.MAX_VALUE;
                break;
            }
        }
        if(isNeg) return -1*((int)ts);   
        return (int)ts;
    }
}