import java.util.ArrayList;
import java.util.List;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Set;

public class Main {
    public static List<int[]> solution(int[][] mat) {
        List<int[]> st = new ArrayList<>();
        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {
                if (mat[i][j] > 0) {
                    st.add(new int[]{mat[i][j], i, j});
                }
            }
        }
        
        List<int[]> res = new ArrayList<>();
        st.sort(Comparator.comparingInt(arr -> arr[0]));
        for (int[] arr : st) {
            int d = arr[0];
            int i = arr[1];
            int j = arr[2];
            boolean f = true;
            for (int[] other : st) {
                int m = other[0];
                int y = other[1];
                int x = other[2];
                if (m < d) {
                    continue;
                }
                if (y == i && x == j) {
                    continue;
                }
                if (i - d <= y && y <= i + d && j - d <= x && x <= j + d
                        && !((y == i - d && x == j - d) || (y == i + d && x == j + d)
                        || (y == i + d && x == j - d) || (y == i - d && x == j + d))) {
                    f = false;
                    break;
                }
            }
            if (f) {
                res.add(new int[]{i, j});
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[][] mat = {
            {3, 0, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 2, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0},
            {0, 3, 0, 0, 3}
        };
        
        List<int[]> result = solution(mat);
        for (int[] arr : result) {
            System.out.println("(" + arr[0] + ", " + arr[1] + ")");
        }
    }
}
