import java.util.HashMap;
import java.util.Map;

class Main {

    public static String solve(String s) {
        s += " ";
        String delimiter = " ";

        String[] tokens = s.split(delimiter);
        Map<String, Integer> mp = new HashMap<>();
        mp.put("zero", 0);
        mp.put("one", 1);
        mp.put("two", 2);
        mp.put("three", 3);
        mp.put("four", 4);
        mp.put("five", 5);
        mp.put("six", 6);
        mp.put("seven", 7);
        mp.put("eight", 8);
        mp.put("nine", 9);

        Map<String, Integer> kmp = new HashMap<>();
        kmp.put("double", 2);
        kmp.put("triple", 3);

        StringBuilder res = new StringBuilder();
        int cur = 1;

        for (String token : tokens) {
            if (kmp.containsKey(token)) {
                cur = kmp.get(token);
            } else {
                while (cur-- > 0) {
                    res.append(mp.get(token));
                }
                cur = 1;
            }
        }

        return res.toString();
    }

    public static void main(String[] args) {
        System.out.println(solve("one two three double two one triple three one"));
    }
}
