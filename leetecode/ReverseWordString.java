import java.util.Arrays;
import java.util.regex.Pattern;

class Solution {
    public String reverseWords(String s) {
        Pattern p = Pattern.compile("\\s");
        String[] strs = p.split(s.trim());
        System.out.println(Arrays.toString(strs));
        return "";

    }
}