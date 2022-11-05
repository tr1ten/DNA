import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Queue;
import java.util.concurrent.LinkedBlockingQueue;

class Solution {
    int count(String s,String mut){
        int c =0; 
        for(int i=0;i<8;i++){
             if(s.charAt(i)!=mut.charAt(i)) c++;
        }
        return c;
    }
    public int minMutation(String start, String end, String[] bank) {
        Queue<int[]> q = new LinkedBlockingQueue<>();
        q.offer(new int[]{-1,0});
        int n =bank.length;
        HashMap<Integer,List<Integer>> map = new HashMap<>();
        for (int i = -1; i < n; i++) {
            map.put(i, new ArrayList<>());
            String s = i == -1 ? start : bank[i];
            for (int j = 0; j < n; j++) {
                if(count(start,bank[j])==1) map.get(i).add(j);
            }
        }
        while(!q.isEmpty()){
            int[] p = q.poll();
            String s = p[0]<0 ? start : bank[p[0]];
            int lvl = p[1];
            if(s.equals(end)) return lvl;
            if(!map.containsKey(p[0])) continue;
            for(int a:map.get(p[0])){
                q.offer(new int[]{a,lvl+1});        
            }
        }
        return -1;
    }
}