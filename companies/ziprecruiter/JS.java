import java.util.*;

class Solution {
    public static int solve(int[][] mat, int size) {
        Map<Integer, Set<Integer>> d = new HashMap<>();

        for (int i = 0; i <= mat.length - size; i++) {
            for (int j = 0; j <= mat[0].length - size; j++) {
                int sm = 0;
                Set<Integer> st = new HashSet<>();
                for (int k = i; k < i + size; k++) {
                    for (int l = j; l < j + size; l++) {
                        sm += mat[k][l];
                        st.add(mat[k][l]);
                    }
                }
                d.computeIfAbsent(sm, key -> new HashSet<>()).addAll(st);
            }
        }

        int maxSum = Collections.max(d.keySet());
        return d.get(maxSum).stream().mapToInt(Integer::intValue).sum();
    }

    public static void main(String[] args) {
        int[][] mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        int size = 2;
        int result = solve(mat, size);
        System.out.println(result);
    }
}