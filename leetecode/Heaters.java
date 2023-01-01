import java.util.Arrays;
import java.util.function.Function;

class Solution {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(houses);
        Arrays.sort(heaters);
        Function<Integer,Boolean> ok = (r)->{
            int p1 = 0;
            int len = houses.length;
            for (int i = 0; i < heaters.length && p1<houses.length && len>0; i++) {
                while (p1<houses.length && houses[p1]<heaters[i]-r) p1++;
                while (p1<houses.length && houses[p1]<=heaters[i]+r) {
                    p1++;
                    len--;
                }
            }
            return len==0;
        };
        int low = 0;
        int high = 1_000_000_000;
        while (low<high) {
            int mid = (low+high)/2;
            if(ok.apply(mid)) high = mid;
            else low = mid+1;
        }
        return low;
    }
}