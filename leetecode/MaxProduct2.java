class Solution { 
    boolean isPalindrome(StringBuilder s){
        int n = s.length();
        for(int i=0;i<n/2;i++){
            if(s.charAt(i)!=s.charAt(n-i-1)) return false;
        }
        return true;
    }
    int solve(String s,int i,StringBuilder left,StringBuilder right){
        int n = s.length();
        if(i>=n) {
            if(isPalindrome(left) && isPalindrome(right)) return left.length()*right.length();
            return 0;
        }
        int wo = solve(s, i+1, left, right);
        right.append(s.charAt(i));
        int r = solve(s, i+1, left, right);
        right.deleteCharAt(right.length()-1);
        left.append(s.charAt(i));
        int l = solve(s, i+1, left, right);
        left.deleteCharAt(left.length()-1);
        return Math.max(Math.max(r, l),wo);
        
    }
    public int maxProduct(String s) {
        return solve(s, 0, new StringBuilder(), new StringBuilder());
    }
}