import java.util.Arrays;
import java.util.stream.Collector;
import java.util.stream.Collectors;

class Solution {
    public String truncateSentence(String s, int k) {
        String[] sd = new StringBuilder(s).reverse().toString().split(" ");
        return Arrays.stream(sd).skip(sd.length-k).collect(Collectors.joining(" "));
    }
}