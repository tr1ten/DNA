import java.util.*;

class Main {
    public static void main(String[] args) {
        int[] A = {3, 3, 3, 4, 4, 1, 8};
        int result = solve(A);
        System.out.println(result);
    }

    static class Counter {
        Map<Integer, Integer> map = new HashMap<>();

        void add(int x) {
            map.put(x, map.getOrDefault(x, 0) + x);
        }
    }

    static int[] A;
    static Counter cnt;
    static List<Integer> si;

    public static int solve(int[] inputArray) {
        A = inputArray;
        cnt = new Counter();
        
        for (int x : A) {
            cnt.add(x);
        }
        si = new ArrayList<>(cnt.map.keySet());
        si.sort((a, b) -> a-b);

        Map<String, Integer> memo = new HashMap<>();
        return dp(0, false, memo);
    }

    public static int dp(int idx, boolean taken, Map<String, Integer> memo) {
        if (idx == si.size()) return 0;
        
        String key = idx + "_" + taken;
        if (memo.containsKey(key)) {
            return memo.get(key);
        }

        int res = dp(idx + 1, false, memo);
        if (!taken || !cnt.map.containsKey(si.get(idx) - 1)) {
            res = Math.max(res, cnt.map.get(si.get(idx)) + dp(idx + 1, true, memo));
        }

        memo.put(key, res);
        return res;
    }
}
