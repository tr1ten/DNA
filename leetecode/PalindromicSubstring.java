class Solution {
    public int countSubstrings(String s) {
        int n = s.length();
        int res=0;
        for(int i=0;i<n;i++){
            int p1 = i;
            int p2 =i;
            while(p1>=0 && p2<n){
                if(s.charAt(p1--)==s.charAt(p2++)) res++;
                else break;
            }
        }
        for(int i=0;i<n;i++){
            int p1 = i;
            int p2 =i+1;
            while(p1>=0 && p2<n){
                if(s.charAt(p1--)==s.charAt(p2++)) res++;
                else break;
            }
        }
        return res;
    }
}