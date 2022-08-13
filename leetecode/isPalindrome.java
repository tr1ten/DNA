class Solution {
    public int lengthOfLastWord(String s) {
        int i=s.length()-1;
        int ct = 0;
        while (s.charAt(i) ==' ') {
            i--;
        }
        while (i>=0 && s.charAt(i) !=' ') {
            ct++;
            i--;
        }

        return ct;
    }
}