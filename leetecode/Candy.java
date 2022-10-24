import java.util.Arrays;

class Solution {
    public int candy(int[] ratings) {
        int[] l2r = new int[ratings.length];
        int[] r2l = new int[ratings.length];
        Arrays.fill(l2r, 1);
        Arrays.fill(r2l, 1);
        for (int i = 1; i < l2r.length; i++) {
            if(ratings[i-1]<ratings[i]) l2r[i]+=l2r[i-1];
        }
        for (int i = r2l.length-2; i >=0; i--) {
            if(ratings[i+1]<ratings[i]) r2l[i]+=r2l[i+1];
        }
        int res=0;
        for (int i = 0; i < r2l.length; i++) {
            res +=Math.max(l2r[i], r2l[i]);
        }
        System.out.println(Arrays.toString(r2l) + Arrays.toString(l2r));
        return res;
    }
}