package leetecode;

import java.util.*;

public class TopKFreq {
    public int[] topKFrequent(int[] nums, int k) {
        ArrayList<Integer> sols = new ArrayList<>();
        ArrayList<Integer> sortedList = new ArrayList<>();
        HashMap<Integer,Integer> hm = new HashMap<>();
        for (int i : nums) {
            sortedList.add(i);
        }
        sortedList.sort(null);
        int lastEl = sortedList.get(0);
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            int temp = sortedList.get(i);
            if(i==0){
                lastEl = temp;
                count = 1;
                continue;
            }
            if(temp==lastEl) count ++;
            else {
                hm.put(lastEl,count);
                count = 1;
            }
            lastEl = temp;            
        }
        hm.put(lastEl,count);
        int[] res = new int[k];
        ArrayList<Integer> distinctItem = new ArrayList<>(hm.keySet());
        class Compare{
            public int compareTo(int a, int b){
                return hm.get(b).compareTo(hm.get(a));
            }
        }
        Compare cm = new Compare();
        distinctItem.sort(cm::compareTo);
        for (int i = 0; i < k; i++) {
            res[i] = distinctItem.get(i);
        }
        return res;
    }

    public static void main(String[] args) {
        TopKFreq tkf = new TopKFreq();
        int[] nums = {5,2,5,3,5,3,1,1,3};
        int k = 2;
        int[] res = tkf.topKFrequent(nums,k);
        for (int i : res) {
            System.out.println(i);
        }
    }
    
}
