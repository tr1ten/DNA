import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int t = sc.nextInt();
        int[] A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }
        System.out.println(solve(A, t));
    }

    public static int solve(int[] A, int t) {
        int ans = 0;
        int lo = 1;
        int hi = 100000; // 10^5 as in your Python code

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (ok(A, t, mid)) {
                hi = mid - 1;
                ans = mid;
            } else {
                lo = mid + 1;
            }
        }

        return ans;
    }

    public static boolean ok(int[] A, int t, int x) {
        int cur = 0;
        int m = 1;
        
        for (int k : A) {
            if (k > x) {
                return false;
            }
            
            if (cur + k > x) {
                cur = 0;
                m++;
            }
            
            cur += k;
        }
        
        return m <= t;
    }
}
