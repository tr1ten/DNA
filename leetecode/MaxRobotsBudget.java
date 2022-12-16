import java.util.Collection;
import java.util.Collections;
import java.util.Deque;
import java.util.Map.Entry;
import java.util.concurrent.LinkedBlockingDeque;
import java.util.concurrent.atomic.DoubleAccumulator;
import java.util.PriorityQueue;
import java.util.TreeMap;

class Solution {
    public int maximumRobots(int[] ct, int[] rc, long bg) {
        Deque<Integer> dq  = new LinkedBlockingDeque<>();
        long sm = 0;
        int n = ct.length;
        int sz = 0;
        int res = 0;
        for (int i = 0; i <n; i++) {
            sm += rc[i];
            sz+=1;
            while (!dq.isEmpty() && dq.getLast()<ct[i]) dq.removeLast();
            dq.offerLast(ct[i]);
            while(!dq.isEmpty() && dq.peekFirst()+sm*sz>bg){
                if(dq.peekFirst()==ct[i-sz+1]) dq.pollFirst();
                sm -= rc[i-sz+1];
                sz -=1;
            }
            res = Math.max(res, sz);
        }
        return res;
    }
}