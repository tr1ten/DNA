package DS;

import java.util.HashMap;

public class QuickUnionWt {
    private int[] parent;   // parent[i] = parent of i
    private int[] size;     // size[i] = number of elements in subtree rooted at i
    private int count;      // number of components

    public QuickUnionWt(int n) {
        count = n;
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    public int count() {
        return count;
    }

    public int find(int p) {
        validate(p);
        while (p != parent[p])
            p = parent[p];
        return p;
    }
    public boolean connected(int p, int q) {
        return find(p) == find(q);
    }

    // validate that p is a valid index
    private void validate(int p) {
        int n = parent.length;
        if (p < 0 || p >= n) {
            throw new IllegalArgumentException("index " + p + " is not between 0 and " + (n-1));  
        }
    }

    public void union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) return;

        // make smaller root point to larger one
        if (size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        count--;
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