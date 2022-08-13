package leetecode;
import java.util.HashSet;;
public class IntersectionArray {
    public int[] intersection(int[] nums1, int[] nums2) {
        final var ls = new HashSet<Integer>();
        final var hs = new HashSet<Integer>();
        
        for (int ni : nums2) {
            hs.add(ni);
        }
        for (int mi : nums1) {
            if(hs.contains(mi)) ls.add(mi);
        }
        var res = new int[ls.size()];
        int i = 0;
        for(int x:ls){
            res[i] = x;
            i++;

        }
        return res;
        
    }
}