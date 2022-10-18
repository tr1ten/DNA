import java.util.*;
class SortItems {
    List<Integer>[] adj;
    LinkedList<Integer> top;
    boolean[] marked;
    boolean dfs(int u,boolean[] visited){
        marked[u] = true;
        for(int v:adj[u]){
            if(visited[v]) return false;
            if(!marked[v]){
                visited[v] = true;
                if(!dfs(v, visited)) return false;
                visited[v] = false;
            }
        }
        top.addFirst(u);
        return true;
    }
    public int[] sortItems(int n, int m, int[] g, List<List<Integer>> bi) {
        adj = new ArrayList[n+2*m];
        int[] res = new int[n];
        top = new LinkedList<>();
        for (int i=0;i<(n+2*m);i++) {
            adj[i] = new ArrayList<>();
        }
        for(int i=0;i<n;i++){
            if(g[i]!=-1){
                adj[n+g[i]].add(i);
                adj[i].add(n+m+g[i]);
            }
            for (int rel:bi.get(i)) {
                int from,to;
                if(g[rel]!=-1 &&  g[rel]==g[i]){
                    from = rel;
                    to = i;
                }
                else{
                    from = g[rel] == -1 ? rel : (n+m+g[rel]);
                    to = g[i] == -1 ? i : (n+g[i]);
                }
                adj[from].add(to);
            }
        }
        marked = new boolean[n+2*m];
        for (int i = adj.length-1; i >=0; i--) {
            if(!marked[i]){
                boolean[] visited = new boolean[n+2*m];
                visited[i] = true;
                if(!dfs(i, visited)) return new int[0];
            }
        }
        int k=0;
        Iterator<Integer> it = top.iterator();
        while (it.hasNext()) {
            int item = it.next();
            if(item<n) res[k++] = item;
        }
        return res;

    }
    public static void main(String[] args) {
        SortItems s = new SortItems();
        int n = 8;
        int m = 2;
        int[] g = {-1,-1,1,0,0,1,0,-1};
        List<List<Integer>> bi = new ArrayList<>();
        bi.add(new ArrayList<>());
        bi.add(new ArrayList<>());
        bi.add(new ArrayList<>());
        bi.add(new ArrayList<>());
        bi.add(new ArrayList<>());
        bi.add(new ArrayList<>());
        bi.add(new ArrayList<>());
        bi.add(new ArrayList<>());
        bi.get(1).add(6);
        bi.get(2).add(5);
        bi.get(3).add(6);
        bi.get(4).add(6);
        bi.get(4).add(3);
           int[] res = s.sortItems(n, m, g, bi);
        for (int i = 0; i < res.length; i++) {
            System.out.print(res[i]+" ");
        }
    }
}