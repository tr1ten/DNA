import java.util.*;
class Solution {
    public String shortestSuperstring(String[] words) {
        // create adjacancy list with wts as length of overlap
        int n = words.length;
        int[][] adj = new int[n][n];
        // for(int[] a:adj) Arrays.fill(a, -200);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                adj[i][j] = -1*overlap(words[i],words[j]);
            }
        }
        TPS tp = new TPS();
        int mc = Integer.MAX_VALUE;
        int[] res=null;
        for (int S = 0; S < n; S++) {
            tp.tps(adj,S);
            if(mc>tp.minCost()){
                mc = tp.minCost();
                res = tp.buildTour();
            }

        }
        System.out.println(Arrays.toString(res));
        StringBuilder sb = new StringBuilder();
        // build ans
        for (int i = 0; i < n-1; i++) {
            int v = res[i];
            int u = res[(i+1)%n];
            int o = -1*adj[v][u];
            if(i==0) sb.append(words[v]);
            sb.append(words[u].substring(o));
        }
        System.out.println("Min cost: "+ sb.length());
        return sb.toString();
    }

    private int overlap(String string, String string2){
        int n = string.length();
        int m = string2.length();
        for(int i=Math.min(n,m);i>=0;i--){
            if(string.substring(n-i).equals(string2.substring(0,i))){
                return i;
            }
        }
        return 0;
    }
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.shortestSuperstring(new String[]{"phuutlgczfspygaljkv","fspygaljkvahvuii","csywjodtnkynkjckq","poyykqyrhbvcwvjl","xijupvzzwphuutlg","aljkvahvuiivqbqrw","vahvuiivqbqrwryd","wjodtnkynkjckqurgu","ecdmbshotqbxjqgbou","hvuiivqbqrwrydgnr","ivqbqrwrydgnrubcsywj","wphuutlgczfspyga"}));
    }
}

class TPS {
    private int[][] mem;
    private int[][] m;
    private int n;
    private int S;

    private static void setup(int[][] m,int[][] mem,int S,int n){
        for(int v=0;v<n;v++){
            if(v==S) continue;
            // ending at v, add them in visited state
            mem[v][1<<S | 1<< v] = m[S][v];
        }
    }
    private static void combinations(int set,int at,int r,int n,List<Integer> subsets){
        if(r==0) subsets.add(set);
        else for (int i = at; i <n; i++) combinations(set | 1<<i, i+1, r-1, n, subsets);
        
    }
    // all combinations of n bits where r bits set to 1 eg. {00111,10110,...} for r=3,n=5
    private static List<Integer> combinations(int r,int n){
        List<Integer> sets = new ArrayList<>();
        combinations(0,0,r,n,sets);
        return sets;
    }
    static boolean  notIn(int state,int v){
        return (state&(1<<v))==0;
    }
    // solve for len 3 to n
    private static void solve(int[][] m,int[][] mem,int S,int n){
        for (int r = 3; r <=n; r++) {
            for(int set:combinations(r, n)){
                if(notIn(set, S)) continue; // path must contain source
                for (int nxt = 0; nxt < n; nxt++) {
                    if(nxt==S || notIn(set, nxt)) continue;
                    int state = set ^ (1<<nxt); // state/path which doesn't contain nxt
                    int ind=-1;
                    for (int e = 0; e < n; e++) { // find min cost path to connect with nxt
                        if(e==S || e==nxt || notIn(state, e)) continue;
                        if(ind==-1) ind=e;
                        int oldCost = mem[ind][state] + m[ind][nxt];
                        int newCost = mem[e][state] + m[e][nxt];
                        if(newCost<oldCost) ind = e;
                    }
                    mem[nxt][state | (1<<nxt)] = mem[ind][state] + m[ind][nxt];
                }
            }
        }
    }
    // find min cost after including S to S (completing the tour)
    public int minCost(){
        int res = Integer.MAX_VALUE;
        int finalState = (1<<n) -1;
        for (int v = 0; v < n; v++) {
            if(v==S) continue;
            res = Math.min(res, mem[v][finalState]); // connect v to S plus path cost ending with v
        }
        return res;
    }
    public int[] buildTour(){
        int state = (1<<n)-1;
        int[] tour = new int[n+1];
        for (int i = n-1; i>=0; i--) {
            int ind=-1;
            for (int v = 0; v < n; v++) {
                if(v==S || notIn(state, v)) continue;
                if(ind==-1) ind = v;
                if(mem[v][state]<mem[ind][state]) ind = v;
            }
            tour[i] = ind;
            state = state ^ (1<<ind);
        }
        tour[0] = S;
        tour[n] = S;
        return tour;
    }
    public void tps(int[][] graph,int source) { // assuming adjacancy matrix with graph[u][v] -> wt (u,v), INF if not edge
        n = graph.length;
        m = graph;
        int MAX = 20000; // MAX distance
        S = source; // arbitrary source
        // mem[end_vertex][state] -> min distance
        mem = new int[n][1<<n]; // state - visited nodes represented as a bit eg. 0001 0th node visited
        for (int[] is : mem) Arrays.fill(is, MAX);
        // initial setup - fill for len 2
        setup(graph, mem, S, n);
        // for len 3 to n (hamiltonian path)
        solve(graph, mem, S, n);
        // find min cost
        

    }

    
}