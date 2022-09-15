import java.util.Iterator;
import java.util.LinkedList;
import java.util.ListIterator;

public class HandsStraight {
    public boolean isNStraightHand(int[] hand, int groupSize) {
        LinkedList<Integer> ll = new LinkedList<>();
        int k=groupSize;
        while (ll.size()>0) {
            Iterator<Integer> it = ll.iterator();
            int last = -1;
            while (it.hasNext()) {
                int c = it.next();
                if(last==c) continue;
                if(last!=-1 && (c-last)!=1) return false;
                it.remove();
                k--;
                if(k==0) k=groupSize;
            }
        }
        return k==0;
    }
}
