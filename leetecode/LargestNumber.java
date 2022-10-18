import java.util.Arrays;
import java.util.Stack;

class Solution {
    public String largestNumber(int[] nums) {
        Integer[] input = Arrays.stream(nums).boxed().toArray(Integer[]::new);
        Arrays.sort(input,
                   (a,b)->{
                       Stack<Integer> st1 = new Stack<>();
                       Stack<Integer> st2 = new Stack<>();
                       while(a>0){
                        st1.push(a%10);
                         a /=10;
                       }
                       while(b>0){
                        st2.push(b%10);
                         b /=10;
                       }
                       System.out.println("st1.size()="+st1+", st2="+st2);

                       while(st1.size()>1 && st2.size()>1){
                           int a1 = st1.pop();
                           int a2 = st2.pop();
                           if(a1>a2) return -1;
                           if(a2>a1) return 1;
                       }
                       Stack<Integer> lower;
                       Stack<Integer> higher;
                       int rt1 = 0;
                       int rt2 = 0;
                       if(st1.size()==1){
                          lower = st1;
                           higher=st2;
                           rt1=-1;
                           rt2 = 1;
                       }
                       else{
                           lower = st2;
                            higher = st1;
                           rt1 = 1;
                           rt2 = -1;
                       }
                    while(!higher.isEmpty()){
                        int k = higher.pop();
                        if(k>lower.peek()) return rt2;
                        if(k<lower.peek()) return rt1;
                    }
                       return 0;
                       
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