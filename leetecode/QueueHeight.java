import java.util.Arrays;

class Solution {
    public int[][] reconstructQueue(int[][] people) {
        int n = people.length;
        int[][] ans = new int[n][2];
        Arrays.sort(people,(a,b)->a[0]!=b[0] ? a[0]-b[0] : a[1]-b[1]);
        for (int[] is : ans) {
            is[0] = -1;
        }
        for (int[] is : people) {
            int h=is[0],cnt=is[1];
            int i=0;
            while (cnt>0) {
                if(ans[i][0]==-1 || ans[i][0]>=h){
                    cnt--;
                }
                i++;
            }
            while(ans[i][0]!=-1) i++;
            ans[i] = is;
        }
        return ans;
    }
} 