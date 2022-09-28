/* package codechef; // don't place package name! */

import java.util.*;
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
			int A = s.nextInt();
			int B = s.nextInt();
			// take nth roots of A untill >=2 and store in array
			HashSet<Double> hm = new HashSet<>();
			int i = 1;
			while (Math.pow(A*1.0, 1.0 / i) >= 2) {
				hm.add(Math.pow(A, 1.0 / i));
				i++;
			}
			// take nth roots of B untill >=2 and store in array
			i = 1;
			boolean flag = false;
			while (Math.pow(B*1.0, 1.0 / i) >= 2) {
				if(hm.contains(Math.pow(B*1.0, 1.0 / i))){
					System.out.println("YES");
					flag = true;
					break;
				}
				i++;
			}
			if(A==1 && B==1){
				System.out.println("YES");
			}
			else if(!flag){
				System.out.println("NO");
			}
	}
}
}