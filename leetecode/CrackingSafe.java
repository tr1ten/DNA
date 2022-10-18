import java.util.HashMap;

// euler circuit
class Solution {
    StringBuilder sb;
    public String crackSafe(int n, int k) {
        // mentain prefix of fixed length to decide what to choose next
        HashMap<String,Integer> map = new HashMap<>();
        StringBuilder allComb = new StringBuilder();
        for(int i=0;i<n-1;i++) allComb.append("0");
        for (int i=0;i<Math.pow(k, n);i++) {
            String prefix = allComb.length() < n ? allComb.toString() : allComb.substring(allComb.length()-n+1,allComb.length());
            map.put(prefix, map.getOrDefault(prefix,k)-1);
            allComb.append(Integer.toString(map.get(prefix)));

        }
        return allComb.toString();
    }
}