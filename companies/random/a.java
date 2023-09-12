import java.util.*;

class Main {
    public static List<Integer> solution(int[][] lamps, int[] points) {
        Set<Integer> si = new HashSet<>();
        for (int[] lamp : lamps) {
            si.add(lamp[0]);
            si.add(lamp[1]);
        }
        for (int x : points) {
            si.add(x);
        }
        
        List<Integer> siList = new ArrayList<>(si);
        Collections.sort(siList);
        
        int[] diff = new int[siList.size() + 1];
        for (int[] lamp : lamps) {
            int index1 = Collections.binarySearch(siList, lamp[0]);
            int index2 = Collections.binarySearch(siList, lamp[1]);
            diff[index1] += 1;
            diff[index2 + 1] -= 1;
        }
        for (int i = 1; i < diff.length; i++) {
            diff[i] += diff[i - 1];
        }
        
        List<Integer> ans = new ArrayList<>();
        for (int x : points) {
            int index = Collections.binarySearch(siList, x);
            ans.add(diff[index]);
        }
        
        return ans;
    }

    public static void main(String[] args) {
        int[][] lamps = {{1, 7}, {5, 11}, {7, 9}};
        int[] points = {7, 1, 5, 10, 9, 15};
        List<Integer> result = solution(lamps, points);
        System.out.println(result);
    }
}
