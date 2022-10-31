import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Iterator;
import java.util.Stack;

class Solution {
    public int[] secondGreaterElement(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        Deque<Integer> nxtGreator = new ArrayDeque<>();
        Deque<Integer> aux  = new ArrayDeque<>();
        for (int i = n-1; i>=0; i--) {
            res[i] = -1;
            Stack<Integer> temp = new Stack<>();
            while (!nxtGreator.isEmpty() && nums[nxtGreator.peek()]<=nums[i]) {
                temp.push(nxtGreator.pop());
            }
            while (!temp.isEmpty()) {
                aux.addLast(temp.pop());
            }
            if(!nxtGreator.isEmpty()){
                System.out.println("here stack " + nxtGreator + " other " + aux + " for " +i);
                int ni = nxtGreator.pollLast();
                Iterator<Integer> desc = aux.descendingIterator();
                Integer nni=null;
                while (desc.hasNext()) {
                    nni = desc.next();
                    if(nums[nni]>nums[i]) break;
                    else nni = null;
                }
                if(!nxtGreator.isEmpty()) res[i] = nni==null ? nums[nxtGreator.getLast()] : nums[Math.min(nni, nxtGreator.getLast())];
                else if(nni!=null) res[i] = nums[nni];
                nxtGreator.addLast(ni);
            }
            nxtGreator.addLast(i);
        }
        return res;
    }
}