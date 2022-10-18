import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Set;
import java.util.Stack;

class RandomizedSet {
    HashMap<Integer,Integer> hm;
    ArrayList<Integer> arr;
    public RandomizedSet() {
        hm = new HashMap<>();
        arr = new ArrayList<>();
    }
    
    public boolean insert(int val) {
        if(hm.containsKey(val)) return false;
        arr.add(val);
        hm.put(val,arr.size()-1);
        return true;
    }
    
    public boolean remove(int val) {
        if(!hm.containsKey(val)) return false;
        int li =hm.get(val);
        int fi = arr.size()-1;
        Collections.swap(arr,fi, li);
        hm.put(arr.get(li), li);
        arr.remove(arr.size()-1);
        hm.remove(val);
        return true;
    }
    
    public int getRandom() {
        return arr.get((int)Math.floor(Math.random()*arr.size()));
    }
}
