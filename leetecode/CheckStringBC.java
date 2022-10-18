class Solution {
    public boolean hasAllCodes(String s, int k) {
        int n = s.length();
        int r = k*(1<<k);
        if(r>n) return false;
        int uq = 0;
        StringBuilder sb = new StringBuilder(s.substring(0,k-1));
        HashSet<String> hs = new HashSet<>();
        int p1=0;
        int p2 = k;
        while(p2<n){
            sb.append(s.charAt(p));
            String str = sb.toString();
            if(!hs.contains(str)){
                uq++;
                hs.add(str);
            }
        }
        return uq==r;
    }
}