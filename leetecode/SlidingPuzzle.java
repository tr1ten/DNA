import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashSet;
import java.util.Set;

class SlidingPuzzle {
    static int N = 2;
    static int M = 3;
    public static final int[][] DIRS = {{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};
    final static String finalStateString = "123450";


    String swap(char[] chars, int i, int j){
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
        return new String(chars);
    }
    public int slidingPuzzle(int[][] board) {
        StringBuilder sb = new StringBuilder();
        int startIdx = -1;
        for(int i=0;i<N;i++){
            for (int j = 0; j < M; j++) {
                sb.append(board[i][j]);
                if (board[i][j] == 0)
                    startIdx = i * board[0].length + j;
            }
        }
        String startStateString = sb.toString();
        if(startStateString.equals(finalStateString)) return 0;
        Deque<Pair<Integer, String>> q = new ArrayDeque<>();
        Set<String> visited = new HashSet<>();
        visited.add(startStateString);
        int steps = 0;
        q.offer(new Pair<>(startIdx,startStateString));
        while (!q.isEmpty()) {
            int size = q.size();
            System.out.println("size " + size + " steps " + steps);
            while (size-->0) {
                Pair<Integer,String> state = q.poll();
                char[] chars = state.getValue().toCharArray();
                int zeroIdx = state.getKey();
                for(int nxt:DIRS[zeroIdx]){
                    swap(chars, zeroIdx, nxt);
                    String nxtString = new String(chars);
                    if(nxtString.equals(finalStateString)) return steps+1;
                    if(!visited.contains(nxtString)) 
                    {
                        visited.add(nxtString);
                        q.offer(new Pair<>(nxt, nxtString));
                    }
                    swap(chars, zeroIdx, nxt);

            }
            }
            steps++;
        }
        return -1;
    }
    public static void main(String[] args) {
        SlidingPuzzle sp = new SlidingPuzzle();
        int[][] board = {{1,2,3},{4,0,5}} ; // [[4,1,2],[5,0,3]]
        System.out.println(sp.slidingPuzzle(board));
    }
}

class Pair<K,V>{
    K key;
    V value;
    Pair(K key,V val){
        this.key = key;
        this.value = val;
    }
    K getKey(){
        return key;
    }
    V getValue(){
        return value;
    }
}