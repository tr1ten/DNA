import java.util.*;
class PartitionSum {
    static int lower_bound(List<Integer> array, int key)
    {
 
        int index = Collections.binarySearch(array, key);
 
        if (index < 0) {
 
            return Math.abs(index) - 1;
        }
 
        else {
            while (index > 0) {
 
                if (array.get(index-1) == key)
                    index--;
 
                else
                    return index;
            }
 
            return index;
        }
    }
    public int minimumDifference(int[] nums) {
        int n = nums.length;
        int N = n/2;
        List<Integer>[] left = new ArrayList[N+1];
        List<Integer>[] right = new ArrayList[N+1];
        int sum=0;
        for(int i=0;i<n;i++) sum +=nums[i];
        for(int i=0;i<=N;i++){
            left[i] = new ArrayList<>();
            right[i] = new ArrayList<>();
        }
        for(int mask=0;mask<(1<<N);mask++){
            int sz=0,l=0,r=0;
            for(int i=0;i<N;i++){
                if((mask&(1<<i))!=0){
                    sz++;
                    l += nums[i];
                    r +=nums[N+i];
                }
            }
            left[sz].add(l);
            right[sz].add(r);
        }
        for(int i=0;i<=N;i++){
            Collections.sort(right[i]);
        }
        int res = Math.min(Math.abs(sum-left[N].get(0)-left[N].get(0)),Math.abs(sum-right[N].get(0)-right[N].get(0)));
        for(int i=0;i<=N;i++){
            for(int b:left[i]){
                int lb = lower_bound(right[N-i], b);
                if(lb!=right[N-i].size()) {
                    res = Math.min(Math.abs(sum-2*(b+right[N-i].get(lb))), res);
                }
                if(lb!=0){
                    res = Math.min(Math.abs(sum-2*(b+right[N-i].get(lb-1))), res);
                }
            }
        }
        
        return res;
        
    }
    public static void main(String[] args) {
        PartitionSum obj = new PartitionSum();
        int[] nums = {-36,36};
        System.out.println(obj.minimumDifference(nums));
    }
}