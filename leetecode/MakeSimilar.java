    import java.util.ArrayList;
    import java.util.Arrays;
    import java.util.Collections;

    class Solution {
        public long makeSimilar(int[] nums, int[] target) { 
            ArrayList<ArrayList<Integer>> sortedNums = new ArrayList<>();
            sortedNums.add(new ArrayList<>());
            sortedNums.add(new ArrayList<>());
            ArrayList<ArrayList<Integer>> sortedTarget = new ArrayList<>();
            sortedTarget.add(new ArrayList<>());
            sortedTarget.add(new ArrayList<>());
            for (int i = 0; i < target.length; i++) {
                sortedNums.get(nums[i]%2).add(nums[i]);
                sortedTarget.get(target[i]%2).add(target[i]);
            }
            Collections.sort(sortedNums.get(0));
            Collections.sort(sortedNums.get(1));
            Collections.sort(sortedTarget.get(0));
            Collections.sort(sortedTarget.get(1));
            int cnt = 0;
            for (int j = 0; j < sortedNums.get(0).size(); j++) {
                cnt += (Math.abs(sortedNums.get(0).get(j)-sortedTarget.get(0).get(j))/2);
            }
            for (int j = 0; j < sortedNums.get(1).size(); j++) {
                cnt += (Math.abs(sortedNums.get(1).get(j)-sortedTarget.get(1).get(j))/2);
            }
            return cnt/2;
        }
    }