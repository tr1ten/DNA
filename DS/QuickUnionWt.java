package DS;

class Solution {
    int bfs(int u,List<Integer>[] adj){
        Queue<Integer> q = new LinkedList<>();
        q.add(u);
        int l=0;
        boolean[] vis = new boolean[adj.length];
        vis[u] = true;
        while(!q.isEmpty()){
            int sz = q.size();
            boolean[] temp = new boolean[adj.length];
            while(sz-->0){
                int v = q.poll();
                temp[v] = true;
                for(int x:adj[v]){
                    if(temp[x]) return -1;
                    if(!vis[x]){
                        vis[x] = true;
                        q.add(x);
                    }
                }
            }
            l++;
        }
        return l;
    }
    public int magnificentSets(int n, int[][] edges) {
        List<Integer>[] adj = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<>();
        }
        QuickUnionWt q = new QuickUnionWt(n);
        for (int[] e : edges) {

            adj[e[0]-1].add(e[1]-1);
            adj[e[1]-1].add(e[0]-1);
            q.union(e[0]-1, e[1]-1);
        }
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            int p = q.find(i);
            int k = bfs(i,adj);
            if(k<0) return -1;
            map.put(p, Math.max(map.getOrDefault(p, 0),k));
        }
        return map.values().stream().mapToInt(x->x).sum();
        

    }
}

// Generic Implementation
// public class QuickUnionWt<T> {
//     private HashMap<T,T> parent;   // parent[i] = parent of i
//     private HashMap<T,Integer> size;     // size[i] = number of elements in subtree rooted at i
//     private int count;      // number of components

//     public QuickUnionWt(T[] arr) {
//         count = arr.length;
//         parent = new HashMap<>();
//         size = new HashMap<>();
//         for (int i = 0; i < arr.length; i++) {
//             parent.put(arr[i], arr[i]);
//             size.put(arr[i], 1);
//         }
//     }
//     public int count() {
//         return count;
//     }

//     public T find(T p) {
//         validate(p);
//         while (p != parent.get(p))
//             p = parent.get(p);
//         return p;
//     }
//     public boolean connected(T p, T q) {
//         return find(p) == find(q);
//     }

//     // validate that p is a valid index
//     private void validate(T p) {
//         if (!parent.containsKey(p)) {
//             throw new IllegalArgumentException("Key " + p + " is not in the map");
//         }
//     }

//     public void union(T p, T q) {
//         T rootP = find(p);
//         T rootQ = find(q);
//         if (rootP == rootQ) return;

//         // make smaller root point to larger one
//         if (size.get(rootP) < size.get(rootQ)) {
//             parent.put(rootP, rootQ);
//             size.put(rootQ, size.get(rootQ) + size.get(rootP));
//         }
//         else {
//             parent.put(rootQ, rootP);
//             size.put(rootP, size.get(rootP) + size.get(rootQ));
//         }
//         count--;
//     }
//     public static void main(String[] args) {
//         Integer[] arr = {0,1,2,3,4,5,6,7,8,9};
//         QuickUnionWt<Integer> qu = new QuickUnionWt<>(arr);
//         qu.union(4, 3);
//         qu.union(3, 8);
//         qu.union(6, 5);
//         qu.union(9, 4);
//         qu.union(2, 1);
//         qu.union(8, 9);
//         qu.union(5, 0);
//         qu.union(7, 2);
//         qu.union(6, 1);
//         qu.union(1, 0);
//         qu.union(6, 7);
//         assert qu.count() == 2;
//         assert qu.connected(0, 7);
//         assert qu.connected(8, 9);
//         assert !qu.connected(1, 9);
//         System.out.println(qu.count() + " components");
//     }

// }