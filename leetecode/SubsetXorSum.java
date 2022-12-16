import java.util.stream.IntStream;


class Solution {
    public int subsetXORSum(int[] nums) {
        return IntStream.range(0, 1<<nums.length).reduce(0, (a,mask)-> a+IntStream.range(0, nums.length).filter((i)->((1<<i)&mask)>0).reduce(0, (c,d)->c^nums[d]));
    }
}