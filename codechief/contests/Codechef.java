package contests;

import java.util.*;
import java.io.*;

// class U{
// 	static int minI(int[] a) {
// 		int min = Integer.MAX_VALUE;
// 		int minI = -1;
// 		for(int i = 0; i < a.length; i++) {
// 			if(a[i] < min) {
// 				min = a[i];
// 				minI = i;
// 			}
// 		}
// 		return minI;
// 	}
// 	static int min(int[] a){
// 		int min = Integer.MAX_VALUE;
// 		for(int i=0;i<a.length;i++){
// 			if(a[i]<min)
// 				min = a[i];
// 		}
// 		return min;
// 	} 
// 	static int max(int[] a){
// 		int max = Integer.MIN_VALUE;
// 		for(int i=0;i<a.length;i++){
// 			if(a[i]>max)
// 				max = a[i];
// 		}
// 		return max;
// 	}
// 	public static int binlog( int bits ) // returns 0 for bits=0
// 	{
// 		int log = 0;
// 		if( ( bits & 0xffff0000 ) != 0 ) { bits >>>= 16; log = 16; }
// 		if( bits >= 256 ) { bits >>>= 8; log += 8; }
// 		if( bits >= 16  ) { bits >>>= 4; log += 4; }
// 		if( bits >= 4   ) { bits >>>= 2; log += 2; }
// 		return log + ( bits >>> 1 );
// 	}
// 	// approx binary searh
// 	static int bs(int[] a, int x){
// 		int l = 0;
// 		int r = a.length-1;
// 		int mid = (l+r)/2;
// 		while(l<=r){
// 			if(a[mid]==x)
// 				return mid;
// 			else if(a[mid]>x)
// 				r = mid-1;
// 			else
// 				l = mid+1;
// 			mid = (l+r)/2;
// 		}
// 		// return approx index
// 		return mid;
// 	}
// }

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
			int Q = s.nextInt();
			int[] a = new int[N];
			for(int i=0;i<N;i++){
				a[i] = s.nextInt();
			}
			int[][] b = new int[Q][];
			for(int i=0;i<Q;i++){
				b[i] = new int[2];
				b[i][0] = s.nextInt();
				b[i][1] = s.nextInt();
			}
			boolean sorted= false;
			for (int[] is : b) {
				a[is[0]-1] = is[1];
				// find goodness
				int i =sorted ? is[0]-1 : 1;
				int g=0;
				while (i<N) {
					if(a[i-1]<=a[i]) {
						i++;
						continue;
					}
					int j=i;
					int d = a[i-1]-a[i];
					while (j<N && (j==i || a[j-1]>=a[j])) {
						a[j] +=d*(j-i+1);
						j++;
					}
					g +=d;
					i++;
				}
				sorted = true;
				System.out.println(g);
			}


	}
}
}
