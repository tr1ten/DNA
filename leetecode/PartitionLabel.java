class Solution {
    public List<Integer> partitionLabels(String s) {
        List<Integer> res = new ArrayList<>();
        int n = s.length();
        int[] m = new int[n+1];
        m[n] = 0;
        for(int i=n-1;i>=0;i--){
            m[i] = m[i+1] | 1<<(s.charAt(i) - 'a');
        }
        int flag = 0;
        int k=1;
        for(int i=0;i<n;i++){
            flag = flag | 1<<(s.charAt(i) - 'a');
            if((flag & m[i+1])==0){
                res.add(k);
                flag = 0;
                k=1;
                continue;
            }
            k++;
        }
        return res;
    }
}