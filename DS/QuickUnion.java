package DS;

// not for production, worst case O(N) for both
/**
 * Quick Union Implementation
 * Without Path compression or Wts
 */
public class QuickUnion {
    int[] id; // id represnt the immediate parent of the node
    QuickUnion(int n){
        id = new int[n];
    }
    int find(int x){
        return x==id[x] ? x : find(id[x]); // root is parent of itself in id array
    }
    void union(int p,int q){
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP==rootQ) return;
        id[rootP] = rootQ; // make root of q as parent of root of p
    }
} 