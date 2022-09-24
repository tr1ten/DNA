import java.util.HashMap;

class Solution {
    HashMap<Integer,Boolean> map = new HashMap<>();
    int setbit(int n, int i) {
        return n | (1 << i);
    }
    boolean getbit(int n, int i) {
        return (n & (1 << i)) != 0;
    }
    int sumBitPlaces(int n,int mx){
        int sum=0;
        for (int i = 1; i <=mx; i++) {
            if(!getbit(n,i))
                sum+=i;
        }
        return sum;
    }
    boolean solve(int mx,int t,int hm){
        if(t<=0) return true;
        int key = hm;
        if(map.containsKey(key)) return map.get(key);
        for (int i = mx; i >= 1; i--) {
            if(!getbit(hm,i)){
                if((t-i)<=0 || !solve(mx,t-i,setbit(hm,i))) {
                    map.put(key, true);
                    return true;
                }
            }
        }
        map.put(key, false);
        return false;
    }
    public boolean canIWin(int maxChoosableInteger, int desiredTotal) {
        map = new HashMap<>();
        if(maxChoosableInteger*(maxChoosableInteger+1)/2 < desiredTotal) return false;
        return solve(maxChoosableInteger, desiredTotal,0);
    }
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.canIWin(10,40));
    }
}