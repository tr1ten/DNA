import java.util.*;
import java.util.AbstractMap.SimpleEntry;

class Solution {
    HashMap<SimpleEntry<Integer,String>,Long> map;
    long solve(List<Integer> robot,TreeMap<Integer,Integer> ts,int idx,String s){
        if(idx==robot.size()) return 0L;
        SimpleEntry<Integer,String> key = new SimpleEntry<>(idx, s.substring(Math.max(s.length()-2, 0)));
        if(map.containsKey(key)) return map.get(key);
        Integer fl = ts.floorKey(robot.get(idx));
        long res = Long.MAX_VALUE;
        if(fl!=null) {
            if(ts.get(fl)==1) ts.remove(fl);
            else ts.put(fl,ts.get(fl)-1);
            long abs = Math.abs(robot.get(idx)-fl);
            res = Math.min(res,abs+solve(robot,ts,idx+1,s+"0"));
            ts.put(fl,ts.getOrDefault(fl,0)+1);
        }
        Integer cl = ts.ceilingKey(robot.get(idx));
        
        if(cl!=null && fl!=cl) {
            if(ts.get(cl)==1) ts.remove(cl);
            else ts.put(cl,ts.get(cl)-1);
            long abs = Math.abs(robot.get(idx)-cl);
            res = Math.min(res,abs+solve(robot,ts,idx+1,s+"1"));
            ts.put(cl,ts.getOrDefault(cl,0)+1);
        }
        map.put(key, res); 
        return res;
    }
    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        TreeMap<Integer,Integer> ts = new TreeMap<>();
        map = new HashMap<>();
        for(int[] x:factory) if(x[1]!=0) ts.put(x[0],x[1]);
        Collections.sort(robot);
        long s = solve(robot,ts,0,"");
        return s;
        
    }
}