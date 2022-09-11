import java.util.Arrays;

// class Solution {
//     static int MAX = 1000000007;
//     int sol=0;
//     HashMap<int[],Integer> hm;
//     int res(int[] nums,int idx,int max,int min){
//         int[] key = new int[]{idx,max,min};
//         if(hm.containsKey(key)) return hm.get(key);
//         if(idx>=nums.length) return (max-min);
//         else{
//             int x= (res(nums,idx+1,Math.max(max,nums[idx]),Math.min(min,nums[idx])) +                   res(nums,idx+1,max,min));
//             hm.put(key,x);
//             return x;
//         }
//     }
//     public int sumSubseqWidths(int[] nums) {
//         int sol = 0;
//         hm = new HashMap<>();
//         for(int i=0;i<nums.length;i++){
//             sol +=(res(nums,i+1,nums[i],nums[i]));
//         }
//         return sol;
//     }
// }
class Solution {
    static int MAX = 1000000007;
    public int sumSubseqWidths(int[] nums) {
        int sol = 0;
        int n = nums.length;
        int p1 = 0;
        Arrays.sort(nums);
        for(int i=n-1;i>=0;i--){
            p1=0;
            while(i>=p1){
                sol += (((nums[i] - nums[p1])%MAX)*((1<<(i-p1-1))%MAX))%MAX; 
                sol = sol%MAX;
                p1++;
            }
        }
        return sol;
    }
}

class Solution2 {
    public int sumSubseqWidths(int[] A) {
        int MOD = 1_000_000_007;
        int N = A.length;
        Arrays.sort(A);

        long[] pow2 = new long[N];
        pow2[0] = 1;
        for (int i = 1; i < N; ++i)
            pow2[i] = pow2[i-1] * 2 % MOD;

        long ans = 0;
        for (int i = 0; i < N; ++i)
            ans = (ans + (pow2[i] - pow2[N-1-i]) * A[i]) % MOD;

        return (int) ans;
    }
}