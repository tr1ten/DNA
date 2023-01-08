import java.util.PriorityQueue;
// fk i hate leetcode 
class Solution {
    public int findCrossingTime(int n, int k, int[][] time) {
        // [leftToRighti, pickOldi, rightToLefti, putNewi]
        PriorityQueue<int[]> left = new PriorityQueue<>(
            (a,b)-> (time[a[0]][0]+time[a[0]][2]==time[b[0]][0]+time[b[0]][2]) ? b[0]-a[0] :Integer.compare(time[b[0]][0]+time[b[0]][2],time[a[0]][0]+time[a[0]][2])
        );
        PriorityQueue<int[]> right = new PriorityQueue<>(
            (a,b)-> (time[a[0]][0]+time[a[0]][2]==time[b[0]][0]+time[b[0]][2]) ? b[0]-a[0] :Integer.compare(time[b[0]][0]+time[b[0]][2],time[a[0]][0]+time[a[0]][2])
        );
        PriorityQueue<int[]> up = new PriorityQueue<>((a,b)->Integer.compare(time[a[0]][1],time[b[0]][1]));
        PriorityQueue<int[]> down = new PriorityQueue<>((a,b)->Integer.compare(time[a[0]][3],time[b[0]][3]));
        for (int i = 0; i < k; i++) {
            left.add(new int[]{i,0});
        }
        int last = 0;
        int bt=0;
        for (int t = 0; t < 1e10 && n>0; t++) {
                while (!right.isEmpty() && Math.max(right.peek()[1], bt)+time[right.peek()[0]][2] <= t) {
                    int[] curr = right.poll();
                    last = Math.max(last, t);
                    down.add(new int[]{curr[0],t});
                    System.out.println("From "+ Math.max(curr[1], bt) +" to " + t + " worker " + curr[0] + " crosses the bridge from the right bank to the left bank.");
                    bt = t;
    
                }
                if(right.isEmpty()){
                    while (!left.isEmpty() && (k-left.size())<n && Math.max(left.peek()[1], bt)+time[left.peek()[0]][0] <= t) {
                        int[] curr = left.poll();
                        up.add(new int[]{curr[0],t});
                        System.out.println("From "+Math.max(curr[1], bt) +" to " + t + " worker " + curr[0] + " crosses the bridge from the left bank to the right bank.");
                        bt =t;   
                    }
                }
            while (!up.isEmpty() && up.peek()[1]+time[up.peek()[0]][1] <= t) {
                int[] curr = up.poll();
                right.add(new int[]{curr[0],t});
                System.out.println("From "+curr[1] +" to " + t + " worker " + curr[0] + " picks up the old box.");

            }
            while (!down.isEmpty() && down.peek()[1]+time[down.peek()[0]][3] <= t) {
                int[] curr = down.poll();
                n--;
                left.add(new int[]{curr[0],t});
                System.out.println("From "+curr[1] +" to " + t + " worker " + curr[0] + " puts down the new box.");
            }
        }
        return last;
    }
}