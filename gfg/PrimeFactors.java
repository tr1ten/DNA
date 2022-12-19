import java.util.ArrayList;
import java.util.List;

class Solution
{
    public int[] AllPrimeFactors(int N)
    {
        List<Integer> res = new ArrayList<>();
        for(int i=2;i<=N;i++){
            if(N%i==0){
            res.add(i);    
            while (N%i==0) {
                N /=i;
            }
            }
        }
        return res.stream().mapToInt(Integer::intValue).toArray();
    }
}