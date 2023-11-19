import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static BigInteger[][] mem;
    static String s;

    static BigInteger dp(int idx, int m) {
        if (idx == s.length()) return m == 0 ? BigInteger.ONE : BigInteger.ZERO;
        if (mem[idx][m] != null) return mem[idx][m];
        if (s.charAt(idx) != '?') return dp(idx + 1, (m + (s.charAt(idx) - '0')) % 9);
        BigInteger res = BigInteger.ZERO;
        for (int i = (idx == 0 ? 1 : 0); i < 10; i++) {
            res = res.add(dp(idx + 1, (m + i) % 9));
        }
        mem[idx][m] = res;
        return res;
    }

    static void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        s = sc.next();
        mem = new BigInteger[s.length()][10];
        for (BigInteger[] row : mem) Arrays.fill(row, null);
        System.out.println(dp(0, 0));
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            solve();
        }
    }
}