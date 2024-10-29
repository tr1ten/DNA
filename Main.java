import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    static boolean isValid(int t, ArrayList<Integer> vec) {
        int operations = 0;
        for (int i = 0; i < vec.size(); i++) {
            operations++;
            vec.set(i, vec.get(i) - (t - i));
        }
        if (operations > t) return false;

        for (int value : vec) {
            int adjusted = Math.max(0, value);
            operations += adjusted;
        }
        return operations <= t;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int testCases = scanner.nextInt();
        while (testCases-- > 0) {
            int n = scanner.nextInt();
            int m = scanner.nextInt();
            int[] classroom = new int[m + 1];

            for (int i = 0; i < n; i++) {
                int x = scanner.nextInt();
                classroom[x]++;
            }

            ArrayList<Integer> vec = new ArrayList<>();
            vec.add(1); // for initial infection spread
            for (int count : classroom) {
                if (count > 0) vec.add(count);
            }

            Collections.sort(vec, Collections.reverseOrder());

            int left = 1, right = n, result = 0;
            while (left <= right) {
                int mid = (left + right) / 2;
                ArrayList<Integer> vecCopy = new ArrayList<>(vec);
                if (isValid(mid, vecCopy)) {
                    result = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }

            System.out.println(result);
        }
        scanner.close();
    }
}
