class Solution {
    public String pushDominoes(String s) {
        int n = s.length();
        int[] left = new int[n];
        Arrays.fill(left,Integer.MAX_VALUE);
        int[] right = new int[n];
        Arrays.fill(right,Integer.MAX_VALUE);
        int p = 0;
        while(p<n){
            if(s.charAt(p)=='.') p++;
            else if(s.charAt(p)=='L'){
                int temp = p-1;
                while(temp>=0 && s.charAt(temp)=='.') left[temp] = Math.min(p-temp,left[temp--]);
                p++;
            }   
            else{
                int temp = p;
                p++;
                while(p<n && s.charAt(p)=='.') right[p] = Math.min(p-temp,right[p++]);
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<n;i++){
                if(left[i]==right[i]) sb.append(s.charAt(i));
                else if(left[i]<right[i]) sb.append("L");
                else sb.append('R');
            
        }
        return sb.toString();
        
    }
}