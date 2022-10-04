import java.util.HashMap;

class GfG
{
    int maxLen(int nums[], int n)
    {
        int[] prefix = new int[n+1];
        prefix[1] = nums[0];
        HashMap<Integer,Integer> hm = new HashMap<>();
        hm.put(prefix[0],0);
        hm.put(prefix[1],1);
        for (int i =1; i < prefix.length; i++) {
            prefix[i+1] = nums[i] + prefix[i];
            hm.put(prefix[i+1], i+1);
        }
        int ml = 0;
        for (int i=0;i<n;i++) {
            ml = Math.max(hm.get(prefix[i])-i, ml);
        }
        return ml;
    }
}