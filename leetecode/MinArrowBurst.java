import java.util.Arrays;

public class MinArrowBurst {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points,(a,b)->a[0]==b[0] ? Integer.compare(a[1],b[1]): Integer.compare(a[0],b[0]));
        int i= 0;
        int res=0;
        int n=points.length;
        while(i<n){
            int k =i+1;
            while(k<n && points[i][1] >=points[k][0]){
                k++;
            }
            res++;
            i = k;
        }
        return res;

    }
    public static void main(String[] args) {
        MinArrowBurst s = new MinArrowBurst();
        int[][] points = {{Integer.MIN_VALUE,Integer.MIN_VALUE+1},{Integer.MAX_VALUE-1,Integer.MAX_VALUE}};
        System.out.println(s.findMinArrowShots(points));
    }
}