class Solution {
    static int[] manchersOdd(String s){
        int n = s.length();
        s = "$" + s + "&"; // no need to check for edge case now
        int l=1,r=1; // max boundary
        int[] p = new int[n+2];
        for (int i = 1; i <= n; i++) {
            p[i] = Math.max(0,Math.min(r-i,p[l+r-i])); // handle both cases b>l and b<=l
            while (s.charAt(i-p[i])==s.charAt(i+p[i])) p[i]++; // trivial expand with center as i, only needed if p[i]+i>r
            if(p[i]+i>r){ // update boundries to use this result in next round set i as center 
                r = i+p[i];
                l = i-p[i];
            }
        }
        int[] res = new int[n];
        for (int i = 0; i < n; i++) {
            res[i] = p[i+1];
        }
        return res;
    }
    static int[] manchers(String s){
        StringBuilder sb = new StringBuilder();
        for (char x:s.toCharArray()) {
            sb.append("#"+x);
        }
        sb.append("#");
        int[] d = manchersOdd(sb.toString());
        return d;        
    }
    public String shortestPalindrome(String s) {
        if(s.length()==0) return "";
        int[] p = manchers(s);
        int center = -1;
        int len = 0;
        for (int i = 0; i < p.length; i++) {
            if(p[i]>len && i-p[i]<0){
                center = i;
                len = p[i];
            }
        }
        // System.out.println(Arrays.toString(p)+ " " +center +" " + len);
        StringBuilder sb = new StringBuilder(s).reverse();
        int left = s.length()-((center+len+1)/2);
        while (left>=0) {
            sb.append(sb.charAt(left));
            left--;
        }
        return sb.toString();
        

    }
}