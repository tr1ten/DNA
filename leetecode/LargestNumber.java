import java.util.Arrays;
import java.util.Stack;

class Solution {
    public String largestNumber(int[] nums) {
        Integer[] input = Arrays.stream(nums).boxed().toArray(Integer[]::new);
        Arrays.sort(input,
                   (a,b)->{
                       String s1 = a.toString();
                       String s2 = b.toString();
                       return (s2+s1).compareTo(s1+s2);
                   }
                   );
        StringBuilder sb = new StringBuilder();
        for(int x:input){
            sb.append(String.valueOf(x));
        }
        return sb.toString();
    }
    public static void main(String[] args) {
        Solution s = new Solution();
        int[] input = {34323,3432};
        System.out.println(s.largestNumber(input));
    }
}
//[34323,3432]