
/* package codechef; // don't place package name! */
import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.HashSet;

class U{
	static int minI(int... a) {
		int min = Integer.MAX_VALUE;
		int minI = -1;
		for(int i = 0; i < a.length; i++) {
			if(a[i] < min) {
				min = a[i];
				minI = i;
			}
		}
		return minI;
	}
	static int min(int... a){
		int min = Integer.MAX_VALUE;
		for(int i=0;i<a.length;i++){
			if(a[i]<min)
				min = a[i];
		}
		return min;
	} 
	static int max(int... a){
		int max = Integer.MIN_VALUE;
		for(int i=0;i<a.length;i++){
			if(a[i]>max)
				max = a[i];
		}
		return max;
	}
	public static int binlog( int bits ) // returns 0 for bits=0
	{
		int log = 0;
		if( ( bits & 0xffff0000 ) != 0 ) { bits >>>= 16; log = 16; }
		if( bits >= 256 ) { bits >>>= 8; log += 8; }
		if( bits >= 16  ) { bits >>>= 4; log += 4; }
		if( bits >= 4   ) { bits >>>= 2; log += 2; }
		return log + ( bits >>> 1 );
	}
	// approx binary searh
	static int bs(int[] a, int x){
		int l = 0;
		int r = a.length-1;
		int mid = (l+r)/2;
		while(l<=r){
			if(a[mid]==x)
				return mid;
			else if(a[mid]>x)
				r = mid-1;
			else
				l = mid+1;
			mid = (l+r)/2;
		}
		// return approx index
		return mid;
	}
}
class FastReader {
    BufferedReader br;
    StringTokenizer st;

    public FastReader()
    {
        br = new BufferedReader(
            new InputStreamReader(System.in));
    }

    String next()
    {
        while (st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(br.readLine());
            }
            catch (IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    int nextInt() { return Integer.parseInt(next()); }

    long nextLong() { return Long.parseLong(next()); }

    double nextDouble()
    {
        return Double.parseDouble(next());
    }

    String nextLine()
    {
        String str = "";
        try {
            if(st.hasMoreTokens()){
                str = st.nextToken("\n");
            }
            else{
                str = br.readLine();
            }
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        return str;
    }
}

class Pair<S extends Comparable<S>, T extends Comparable<T>> implements Comparable<Pair<S, T>> {
    S first;
    T second;
    
    Pair(S f, T s) {
        first = f;
        second = s;
    }

    @Override
    public int compareTo(Pair<S, T> o) {
        int t = first.compareTo(o.first);
        if (t == 0) return second.compareTo(o.second);
        return t;
    }
    
    @Override
    public int hashCode() {
        return (31 + first.hashCode()) * 31 + second.hashCode();
    }
    
    @Override
    public boolean equals(Object o) {
        if (!(o instanceof Pair)) return false;
        if (o == this) return true;
        Pair p = (Pair) o;
        return first.equals(p.first) && second.equals(p.second);
    }
    
    @Override
    public String toString() {
        return "Pair{" + first + ", " + second + "}";
    }
}


class Codechef
{
    static Set<Integer> dfs(int u,int p,int[] A,List<Integer>[] adj,HashMap<Pair<Integer,Integer>,Set<Integer>> mem){
        Pair<Integer,Integer> key = new Pair<>(u, p);
        if(mem.containsKey(key)) return mem.get(key);
        HashSet<Integer> res = new HashSet<>();
        res.add(A[u]);
        for(int v:adj[u]){
            if(p==v) continue;
            res.addAll(dfs(v, u, A, adj,mem));
        }
        mem.put(key, res);
        return res;

    }
    // Main Logic
    static void solve(int N,int[] A, int[][] edges){
        List<Integer>[] adj = new ArrayList[N];
        HashMap<Pair<Integer,Integer>,Set<Integer>> mem = new HashMap<>();
        for (int i = 0; i < N; i++) adj[i] = new ArrayList<>();
        for (int[] ed : edges) {
            int u=ed[0],v=ed[1];
            adj[u-1].add(v-1);
            adj[v-1].add(u-1);
        }
        for (int[] ed : edges) {
            int u=ed[0]-1,v=ed[1]-1;
            Set<Integer> s1 = dfs(u, v, A, adj,mem);
            Set<Integer> s2 = dfs(v, u, A, adj,mem);
            s1.retainAll(s2);
            System.out.print(s1.stream().mapToInt(i->i).sum() + " ");
        }
        System.out.println();
    }
	public static void main(String[] args)
	{
		FastReader s = new FastReader();
		int n = s.nextInt();
		while (n-- > 0) {
			int N = s.nextInt();
            int[] A = new int[N];
            for (int i = 0; i < N; i++) {
                A[i] = s.nextInt();
            }
            int[][] edges = new int[N-1][2];
            for (int i = 0; i < N-1; i++) {
                edges[i][0] = s.nextInt();
                edges[i][1] = s.nextInt();
            }
            solve(N, A, edges);
			
	}
}
}
