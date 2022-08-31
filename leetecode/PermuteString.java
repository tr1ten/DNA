class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int[] count = new int[26];
        boolean[] ex = new boolean[26];
        int n1  = s1.length();
        int n2 = s2.length();
        for(int i=0;i<n1;i++) {
            count[s1.charAt(i) - 'a'] +=1;
            ex[s1.charAt(i) - 'a'] = true;
        
        }
        int p1 = 0,p2 =n1-1;
        int[] temp = count.clone();
        while(p2<n2){
            boolean flag = true;
            for(int i=p1;i<=p2;i++){
                int key = s2.charAt(i) - 'a';
                if(!ex[key] || temp[key]<=0) flag = false;
                else temp[key]--;
                if(!flag) break;
            }
            if(flag) return true;
            temp = count.clone();
            p2++;
            p1++;
        }
        return false;
    }
}