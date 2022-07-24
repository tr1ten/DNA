import java.lang.*;

public class ValidPalindrome {
    public static void main(String[] args) {
        isPalindrome("A man, a plan, a canal: Panama");
    }

    public static boolean isPalindrome(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (!Character.isLetterOrDigit(c) || c == ' ') {
                continue;
            } else if (c <= 'Z' && c >= 'A') {
                sb.append((char) (c + 'a' - 'A'));
            } else {
                sb.append(c);
            }
        }
        int i = 0;
        int j = sb.length() - 1;
        while (i < j) {
            if (sb.charAt(i) != sb.charAt(j)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}
