class Solution {
    public int[] maxPoints(int[][] grid, int[] queries) {
        TreeMap<Integer,Integer> ts = new TreeMap<>();
        for(int q:queries){
            ts.put(q,0);
        }
        int[] res = new int[queries.length];
        PriorityQueue<int[]> q = new PriorityQueue<>((a,b)->Integer.compare(a[2],b[2]));
        q.add(new int[]{0,0,grid[0][0]});
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        visited[0][0] = true;
        while(!q.isEmpty()){
            int[] u = q.poll();
            int i=u[0],j=u[1],mx=u[2];
            Integer ck = ts.ceilingKey(mx+1);
            if(ck==null) continue;
            ts.put(ck,ts.get(ck)+1);
            if(i+1<grid.length && !visited[i+1][j]) {
                visited[i+1][j] = true;
                q.add(new int[]{i+1,j,Math.max(mx,grid[i+1][j])});
            }
            if(i-1>=0 && !visited[i-1][j]) {
                visited[i-1][j] = true;
                q.add(new int[]{i-1,j,Math.max(mx,grid[i-1][j])});
            }
            if(j+1<grid[0].length && !visited[i][j+1]) {
                visited[i][j+1] = true;
                q.add(new int[]{i,j+1,Math.max(mx,grid[i][j+1])});
            }
            if(j-1>=0 && !visited[i][j-1]) {
                visited[i][j-1] = true;
                q.add(new int[]{i,j-1,Math.max(mx,grid[i][j-1])});
            }
        }
        int last = 0;
        for(int k:ts.keySet()){
            ts.put(k,ts.get(k)+last);
            last = ts.get(k);
        }
        for(int i=0;i<res.length;i++){
            res[i] = ts.get(queries[i]);
        }
        return res;
    }
}