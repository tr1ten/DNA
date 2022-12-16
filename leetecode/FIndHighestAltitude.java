import java.util.Arrays;
import java.util.stream.IntStream;

class Solution {
    public int largestAltitude(int[] gain) {
        final Integer last = 0;
        return Math.max(0,IntStream.range(0, gain.length).peek((i)->{
            if(i==0) return;
            gain[i] = gain[i]+gain[i-1];
        }).map(i->gain[i]).max().getAsInt());
    }
}