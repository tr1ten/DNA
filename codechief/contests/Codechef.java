/* package codechef; // don't place package name! */

import java.util.*;
import java.util.concurrent.LinkedBlockingQueue;
import java.lang.*;
import java.io.*;

class U{
	static int minI(int[] a) {
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
	static int min(int[] a){
		int min = Integer.MAX_VALUE;
		for(int i=0;i<a.length;i++){
			if(a[i]<min)
				min = a[i];
		}
		return min;
	} 
	static int max(int[] a){
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

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
static class FastReader {
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
	public static void main(String[] args)
	{
		FastReader s = new FastReader();
		int n = s.nextInt();
		while (n-- > 0) {
			int N = s.nextInt();
			TreeMap<Integer, Integer> map = new TreeMap<>(Collections.reverseOrder());
			for(int i = 0; i < N; i++) {
				int x = s.nextInt();
				if(map.containsKey(x)) {
					map.put(x, map.get(x)+1);
				}
				else {
					map.put(x, 1);
				}
			}
			int i=0;
			List<int[]> l = new ArrayList<int[]>();
			while (map.firstKey()!=0 && i<3) {
				// find triplet with min xor
				int minXor = Integer.MAX_VALUE;
				Integer[] arr = new Integer[N];
				int p=0;
				for(int key:map.keySet()){
					int o=map.get(key);
					for(int j=0;j<o;j++){
						arr[p++]=key;
					}
				}
				System.out.println(Arrays.toString(arr));
				// find triplet with min xor
				int a=0,b=0,c=0;
				for (int j = 0; j < N-2; j++) {
					int xor = arr[j] ^ arr[j+1] ^ arr[j+2];
					if(xor < minXor) {
						minXor = xor;
						a = arr[j];
						b = arr[j+1];
						c = arr[j+2];
					}
				}
				int[] t = {a,b,c};
				l.add(t);
				// decrease the value or delete it if zero
				for (int f:t) {
					if(map.get(f) == 1) {
						map.remove(f);
					}
					else {
						map.put(f, map.get(f)-1);
					}
				}
				int[] xort = {a^b,a^c,b^c};
				for (int f:xort) {
					if(map.containsKey(f)) {
						map.put(f, map.get(f)+1);
					}
					else {
						map.put(f, 1);
					}
				}
				i++;
			}
			System.out.println(l.size());
			for (int[] is : l) {
				System.out.println(is[0]+" "+is[1]+" "+is[2]);
			}
	}
}
}

