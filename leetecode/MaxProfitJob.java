import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Stack;
import java.util.TreeMap;

class Solution {
    
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = profit.length;
        Integer[][] ivals = new Integer[n][3];
        for(int i=0;i<n;i++){
            ivals[i] = new Integer[]{startTime[i],endTime[i],profit[i]};
        }
        Arrays.sort(ivals,(a,b)->a[1]-b[1]);
        TreeMap<Integer,Integer> tm = new TreeMap<>();
        tm.put(0, 0);
        for (int i = 0; i < ivals.length; i++) {
            Integer val = ivals[i][2] + tm.floorEntry(ivals[i][0]).getValue();
            if(val>tm.lastEntry().getValue()) tm.put(ivals[i][1], val);
        }
        return tm.lastEntry().getValue();
    }
}