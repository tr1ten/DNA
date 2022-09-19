import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

class Solution {
    public ArrayList<Integer> dNums(ArrayList<Integer> A, int B) {
        ArrayList<Integer> arr = new ArrayList<>();
        if(A.size()<B) return arr;
        HashMap<Integer,Integer> hm = new HashMap<>();
        for(int i=0;i<B;i++){
            hm.put(A.get(i),hm.getOrDefault(A.get(i),0)+1);
        }
        arr.add(hm.size());
        for(int i=B;i<A.size();i++){
            hm.put(A.get(i-B),hm.get(A.get(i-B))-1);
            if(hm.get(A.get(i-B))==0) hm.remove(A.get(i-B));
            hm.put(A.get(i),hm.getOrDefault(A.get(i),0)+1);
            arr.add(hm.size());
        }

        return arr;
    }
}
