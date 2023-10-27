import java.util.*;
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        int result = solution(n);
        System.out.println(result);
    }

    public static int solution(long n) {
        int cnt = 0;
        
        while (n > 2) {
            long t = 5;
            long now = 2;
            
            while (n >= t + now) {
                now = t + now;
                t += 3;
            }
            
            n -= now;
            cnt++;
        }
        
        if (n >= 2) cnt++;
        return cnt;
    }
}